#include "mouse.h"
#include "saferelease.h"

int sim::mouse::x()
{
	return GetInstance().x_;
}
int sim::mouse::y()
{
	return GetInstance().y_;
}

int sim::mouse::vx()
{
	return GetInstance().vx_;
}
int sim::mouse::vy()
{
	return GetInstance().vy_;
}

int sim::mouse::ax()
{
	return GetInstance().ax_;
}
int sim::mouse::ay()
{
	return GetInstance().ay_;
}

int sim::mouse::wheel_forward()		// マウスホイールの今回のフレームの回転量(前方方向プラス)
{
	return GetInstance().wheel_forward_;
}
int sim::mouse::wheel_backward()	// マウスホイールの今回のフレームの回転量(後方方向プラス)
{
	return 0-GetInstance().wheel_forward_;	// 符号反転
}

bool sim::mouse::freeing(ButtonID id)
{
	return GetInstance().abButtonStatus[GetInstance().bActiveIndex][id] == false;
}
bool sim::mouse::pushed(ButtonID id)
{
	return
		GetInstance().abButtonStatus[!(GetInstance().bActiveIndex)][id] == false
		&&
		GetInstance().abButtonStatus[GetInstance().bActiveIndex][id] == true;
}
bool sim::mouse::pushing(ButtonID id)
{
	return GetInstance().abButtonStatus[GetInstance().bActiveIndex][id] == true;
}
bool sim::mouse::clicked(ButtonID id)
{
	return
		GetInstance().abButtonStatus[!(GetInstance().bActiveIndex)][id] == true
		&&
		GetInstance().abButtonStatus[GetInstance().bActiveIndex][id] == false;
}


sim::mouse & sim::mouse::GetInstance()
{
	static mouse mouse_;
	return mouse_;
}
sim::mouse::mouse()
{
	device = nullptr;
}
bool sim::mouse::init(LPDIRECTINPUT8 & diinterface, HWND windle)
{
	bActiveIndex = 0;
	for (int n2 = 0; n2 < 2; ++n2)
	{
		for (int n3 = 0; n3 < 3; ++n3)
		{
			abButtonStatus[n2][n3] = false;
		}
	}

	vx_ = 0;
	vy_ = 0;
	ax_ = 0;
	ay_ = 0;

	HRESULT result = diinterface->CreateDevice(GUID_SysMouse, &device, NULL);
	if (FAILED(result))
	{
		fw::popup("failed to create device of mouse");
		return false;
	}

	result = device->SetDataFormat(&c_dfDIMouse2);
	if (FAILED(result))
	{
		fw::popup("failed to set data-format of mouse");
		return false;
	}

	device->Acquire();
	
	return true;
}
void sim::mouse::update(HWND hwnd)
{
	DIMOUSESTATE2 dims;
	HRESULT result;

	result = device->GetDeviceState(sizeof(DIMOUSESTATE2), &dims);

	if (SUCCEEDED(result))
	{
		bActiveIndex = !bActiveIndex;
		abButtonStatus[bActiveIndex][button_left] = (dims.rgbButtons[0] & (1 << 7) ) != 0;
		abButtonStatus[bActiveIndex][button_right] = (dims.rgbButtons[1] & (1 << 7) ) != 0;
		abButtonStatus[bActiveIndex][button_middle] = (dims.rgbButtons[2] & (1 << 7) ) != 0;

		wheel_forward_ = dims.lZ;

		POINT newxy;

		GetCursorPos(&newxy);
		ScreenToClient(hwnd, &newxy);

		int nOldVX = vx_;
		int nOldVY = vy_;
		vx_ = newxy.x - x_;
		vy_ = newxy.y - y_;
		x_ = newxy.x;
		y_ = newxy.y;
		ax_ = vx_ - nOldVX;
		ay_ = vy_ - nOldVY;
	}
	else
	{
		if (result == DIERR_INPUTLOST)
		{
			device->Acquire();
		}
	}
}

sim::mouse::~mouse()
{
	saferelease(device);
}