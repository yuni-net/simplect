#include <window.h>
#include <manager.h>

bool sim::window::CreateDevice(bool VertiSyncFlag)
{
	struct for_create
	{
		HRESULT operator() (LPDIRECT3D9 & d3d, HWND handle, DWORD flag, D3DPRESENT_PARAMETERS & prepara, LPDIRECT3DDEVICE9 & device)
		{
			return d3d->CreateDevice(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				handle,
				flag, 
				&prepara,
				&device);
		}

	}create;

	fw::zeromemory(&prepara);
	prepara.Windowed = TRUE;
	prepara.SwapEffect = D3DSWAPEFFECT_DISCARD;
	prepara.BackBufferFormat = D3DFMT_UNKNOWN;
	//////////////////////////////////////////////
	prepara.BackBufferWidth = 640;
	prepara.BackBufferHeight = 480;
	//////////////////////////////////////////////
	if(VertiSyncFlag) prepara.Flags = D3DPRESENT_INTERVAL_ONE;
	else prepara.Flags = D3DPRESENT_DONOTWAIT;

	HRESULT hr = create(sim::manager::Get_d3d(), win().myhandle(), D3DCREATE_HARDWARE_VERTEXPROCESSING, prepara, device);

	if(FAILED(hr) )
	{
		hr = create(sim::manager::Get_d3d(), win().myhandle(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, prepara, device);

		if(FAILED(hr) )
		{
			#ifdef MIE_MIENDOW_CREATE_POP_UP_
				fw::popup("failed to create devices");
			#endif

			return false;
		}
	}

	return true;
}