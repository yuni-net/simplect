#include <dx9input.h>
#include <includes.h>

namespace sim
{

	/////////////////////////////////////////////////////////
	//
	// dx9input
	//
	/////////////////////////////////////////////////////////

	LPDIRECTINPUT8 sim::dx9input::diinterface;

	dx9input::dx9input()
	{
		diinterface = NULL;
	}

	bool dx9input::init()
	{
		HRESULT result;

		result = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void **) &diinterface, NULL);
		if (FAILED(result))
		{
			fw::popup("failed to get iDirectInput8 interface");
			return false;
		}

		return true;
	}

	LPDIRECTINPUT8 & dx9input::GetInterface()
	{
		return diinterface;
	}

	dx9input::~dx9input()
	{
		if (diinterface)
		{
			diinterface->Release();
			diinterface = NULL;
		}
	}

}