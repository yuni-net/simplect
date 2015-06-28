#include <dx9key.h>
#include <dx9input.h>
#include <includes.h>



namespace sim
{
	///////////////////////////////////////////////////////////
	//
	// dx9key
	//
	//////////////////////////////////////////////////////////

	BYTE dx9key::keystate[2][256];
	bool dx9key::active;
	int dx9key::pushing_num_;
	int dx9key::freeing_num_;
	int dx9key::pushed_num_;
	int dx9key::clicked_num_;


	dx9key::dx9key()
	{
		device = NULL;
		ZeroMemory(keystate[0], 256);
		ZeroMemory(keystate[1], 256);
	}

	bool dx9key::init(LPDIRECTINPUT8 & diinterface, HWND windle)
	{
		Windle = windle;
		HRESULT result;

		result = diinterface->CreateDevice(GUID_SysKeyboard, &device, NULL);
		if (FAILED(result))
		{
			fw::popup("failed to get IDirectInputDevice8 interface");
			return false;
		}

		result = device->SetDataFormat(&c_dfDIKeyboard);
		if (FAILED(result))
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

		device->Acquire();

		return true;
	}

	void dx9key::update()
	{
		HRESULT result;

		// getting direct data
		result = device->GetDeviceState(256, keystate[!active]);
		if (FAILED(result))
		{
			device->Acquire();
			result = device->GetDeviceState(256, keystate[!active]);
			if (result == DIERR_INPUTLOST)
			{
				release();
				init(dx9input::GetInterface(), Windle);
				result = device->GetDeviceState(256, keystate[!active]);
				if (FAILED(result))
				{
					fw::popup("fatal error in dx9key");
				}
			}
		}

		active = !active;

		pushing_num_ = compute_pushing_num();
		freeing_num_ = compute_freeing_num();
		pushed_num_ = compute_pushed_num();
		clicked_num_ = compute_clicked_num();
	}

	bool dx9key::pushing(unsigned char key)
	{
		return (keystate[active][key] & 0x80) != 0;
	}

	bool dx9key::freeing(unsigned char key)
	{
		return !pushing(key);
	}

	bool dx9key::pushed(unsigned char key)
	{
		if ((keystate[active][key] & 0x80) == 0) return false;
		if ((keystate[!active][key] & 0x80) != 0) return false;

		return true;
	}
	bool dx9key::clicked(unsigned char key)
	{
		if ((keystate[active][key] & 0x80) != 0) return false;
		if ((keystate[!active][key] & 0x80) == 0) return false;

		return true;
	}

	int dx9key::pushing_num()
	{
		return pushing_num_;
	}
	int dx9key::freeing_num()
	{
		return freeing_num_;
	}
	int dx9key::pushed_num()
	{
		return pushed_num_;
	}
	int dx9key::clicked_num()
	{
		return clicked_num_;
	}


	int dx9key::compute_pushing_num()
	{
		int total = 0;
		for (unsigned char nNo = 0; ; ++nNo)
		{
			if (pushing(nNo)) ++total;
			if (nNo == 255) break;
		}

		return total;
	}
	int dx9key::compute_freeing_num()
	{
		int total = 0;
		for (unsigned char nNo = 0; ; ++nNo)
		{
			if (freeing(nNo)) ++total;
			if (nNo == 255) break;
		}

		return total;
	}
	int dx9key::compute_pushed_num()
	{
		int total = 0;
		for (unsigned char nNo = 0; ; ++nNo)
		{
			if (pushed(nNo)) ++total;
			if (nNo == 255) break;
		}

		return total;
	}
	int dx9key::compute_clicked_num()
	{
		int total = 0;
		for (unsigned char nNo = 0; ; ++nNo)
		{
			if (clicked(nNo)) ++total;
			if (nNo == 255) break;
		}

		return total;
	}


	void dx9key::release()
	{
		if (device)
		{
			device->Unacquire();
			device->Release();
			device = NULL;
		}
	}
	dx9key::~dx9key()
	{
		release();
	}

}