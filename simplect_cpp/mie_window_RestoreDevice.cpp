#include <window.h>

bool sim::window::RestoreDevice()
{
	HRESULT hr = device->TestCooperativeLevel();
	if(FAILED(hr) )
	{
		if(hr != D3DERR_DEVICELOST)
		{
			if(hr != D3DERR_DEVICENOTRESET)
			{
				#ifdef MIE_MIENDOW_CLEAR_POP_UP_
					fw::popup("An unexpected error");
				#endif

				return false;
			}

			ReleaseResources();	// Do release resources here that Direct3D don't control

			hr = device->Reset(&prepara);
			if(FAILED(hr) )
			{
				if(hr!=D3DERR_DEVICELOST)
				{
					#ifdef MIE_MIENDOW_CLEAR_POP_UP_
						fw::popup("failed to restore devices");
					#endif
				}
			}
			else
			{
				ResetResources();	// Do Reset resources here that Direct3D don't control
			}
		}
	}

	return true;
}