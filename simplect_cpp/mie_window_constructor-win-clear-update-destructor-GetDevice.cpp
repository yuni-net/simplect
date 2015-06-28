#include <window.h>
#include <manager.h>
#include <joypad.h>
#include <mouse.h>

LPDIRECT3DDEVICE9 sim::window::device;
fw::window sim::window::Win;

sim::window::window()
{
	device = nullptr;
}

fw::window & sim::window::win(){ return Win; }

bool sim::window::create(bool VertiSyncFlag)
{
	saferelease(device);

	win().create();

	if(CreateDevice(VertiSyncFlag)==false) return false;
	if(SetViewPort()==false) return false;

	SetParameter();

	dxkey.init(::sim::manager::GetDX9InputInterface(), win().myhandle() );
	dxjoypad.init(::sim::manager::GetDX9InputInterface(), win().myhandle() );
	sim::mouse::GetInstance().init(sim::manager::GetDX9InputInterface(), win().myhandle() );

	return true;
}

bool sim::window::clear()
{
	RestoreDevice();
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0);
	bool res = bool(SUCCEEDED(device->BeginScene() ) );

	dxkey.update();
	dxjoypad.update();
	sim::mouse::GetInstance().update(win().myhandle() );

	return res;
}

void sim::window::update()
{
	device->EndScene();
	HRESULT res = device->Present(NULL,NULL,NULL,NULL);
	/*
	if (FAILED(res))
	{
		res = device->TestCooperativeLevel();
		if (FAILED(res))
		{
			if (res == D3DERR_DEVICENOTRESET)
			{
				LPDIRECT3DDEVICE9;
				IDirect3DDevice9
				device->Reset(&(sim::manager::Get_d3d()));
			}
		}
	}
	//*/
}

sim::window::~window()
{
	saferelease(device);
}

LPDIRECT3DDEVICE9 & sim::window::GetDevice() 
{
	return device;
}

