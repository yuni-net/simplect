#include <includes.h>
#include <dx9input.h>
#include <dx9joypad.h>
#include <saferelease.h>

//const int ButtonNum = 32;

namespace sim
{
	dx9joypad::dx9joypad()
	{
		active = false;
		buttons[active] = 0;
		X = 0;
		Y = 0;
		device = nullptr;
	}
	bool dx9joypad::init(LPDIRECTINPUT8 & diinterface, HWND windle)
	{
		//	Windle = windle;
		HRESULT result;

		result = diinterface->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoyCallback, NULL, DIEDFL_ATTACHEDONLY);
		if(FAILED(result) )
		{
			fw::popup("failed to enum devices");
			return false;
		}

		if(device == NULL)
		{
		//	fw::popup("Not Found Joypad");
			return false;
		}

		result = device->SetDataFormat(&c_dfDIJoystick);
		if(FAILED(result) )
		{
			fw::popup("failed to set data format");
			return false;
		}

		result = device->SetCooperativeLevel(windle, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		if (FAILED(result))
		{
			fw::popup("failed to set cooperative level");
			return false;
		}


		DIPROPDWORD prop;
		prop.diph.dwSize = sizeof(prop);
		prop.diph.dwHeaderSize = sizeof(prop.diph);
		prop.diph.dwObj = 0;
		prop.diph.dwHow = DIPH_DEVICE;
		prop.dwData = DIPROPAXISMODE_ABS;

		result = device->SetProperty(DIPROP_AXISMODE, &prop.diph);
		if(FAILED(result) )
		{
			fw::popup("failed to set property of DIPROP_AXISMODE");
			return false;
		}


		result = device->EnumObjects(EnumAxesCallback, NULL, DIDFT_AXIS);
		if(FAILED(result) )
		{
			fw::popup("failed to enum axis");
			return false;
		}


		device->Acquire();

		return true;
	}
	void dx9joypad::update()
	{
		if(device == NULL) return;

		OldX = x();
		OldY = y();

		HRESULT result = device->Poll();
		if(FAILED(result) )
		{
			device->Acquire();
			device->Poll();
		}

		DIJOYSTATE js;
		result = device->GetDeviceState(sizeof(DIJOYSTATE), &js);

		X = js.lX;
		Y = js.lY;

		buttons[!active] = 0;
		for(int i=0;i<ButtonNum;++i)
		{
			if( (js.rgbButtons[i] & 0x80) != 0)
			{
				buttons[!active] |= 1<<i;
			}
		}
		active = !active;
	}

	dx9joypad::~dx9joypad()
	{
		if (device)
		{
			device->Unacquire();
			device->Release();
			device = nullptr;
		}
	}


	LONG dx9joypad::X;
	LONG dx9joypad::Y;
	LONG dx9joypad::OldX;
	LONG dx9joypad::OldY;
	unsigned long dx9joypad::buttons[2];
	bool dx9joypad::active;

	LPDIRECTINPUTDEVICE8 dx9joypad::device;
	DIDEVCAPS dx9joypad::devcap;


	BOOL __stdcall dx9joypad::EnumJoyCallback(LPCDIDEVICEINSTANCE devins, LPVOID context)
	{
		LPDIRECTINPUTDEVICE8 & device =  dx9joypad::GetDevice();
		DIDEVCAPS & devcap = dx9joypad::GetDevCap();
		HRESULT result;

		result = dx9input::GetInterface()->CreateDevice(devins->guidInstance, &device, NULL);
		if(FAILED(result) ) return DIENUM_CONTINUE;

		devcap.dwSize = sizeof(DIDEVCAPS);
		result = device->GetCapabilities(&devcap);
		if(FAILED(result) )
		{
			device->Release();
			device = NULL;
			return DIENUM_CONTINUE;
		}

		return DIENUM_STOP;
	}

	BOOL CALLBACK dx9joypad::EnumAxesCallback(LPCDIDEVICEOBJECTINSTANCE lpddoi, LPVOID pvRef)
	{
		HRESULT result;

		DIPROPRANGE diprg;
		ZeroMemory(&diprg, sizeof(diprg) );
		diprg.diph.dwSize = sizeof(diprg);
		diprg.diph.dwHeaderSize = sizeof(diprg.diph);
		diprg.diph.dwObj = lpddoi->dwType;
		diprg.diph.dwHow = DIPH_BYID;
		//////////////////////////////////////////////////
		diprg.lMin = -1000;
		diprg.lMax = 1000;
		//////////////////////////////////////////////////

		result = dx9joypad::GetDevice()->SetProperty(DIPROP_RANGE, &diprg.diph);
		if(FAILED(result) ) return DIENUM_STOP;

		return DIENUM_CONTINUE;
	}
}