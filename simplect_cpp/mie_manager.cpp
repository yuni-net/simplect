#include <manager.h>
#include <dx9input.h>
#include <saferelease.h>

LPDIRECT3D9 sim::manager::d3d;
sim::sound_manager sim::manager::soundm;

sim::manager::manager()
{
	VertiSyncFlag = true;
	d3d = nullptr;
}

void sim::manager::title(const std::string & str)
{
	mainwin.win().title(str);
}

void sim::manager::VertiSync(bool flag)
{
	VertiSyncFlag = flag;
}

bool sim::manager::clear()
{
	return mainwin.clear();
}
void sim::manager::update()
{
	mainwin.update();
}

bool sim::manager::init()
{
	saferelease(d3d);
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if(d3d == NULL) return false;

	if (dxinput.init() == false)
	{
		fw::popup("failed to init dxinput");
		return false;
	}

	mainwin.win().width(640).height(480);
	if (mainwin.create(VertiSyncFlag) == false) return false;

	if (soundm.init() == false)
	{
		return false;
	}

	return true;
}

sim::manager::~manager()
{
	saferelease(d3d);
}

// Don't use this function. this function is used by system
LPDIRECT3D9 & sim::manager::Get_d3d()
{
	return d3d;
}

LPDIRECTINPUT8 & sim::manager::GetDX9InputInterface()
{
	return sim::dx9input::GetInterface();
}

sim::sound_manager & sim::manager::get_sound_manager()
{
	return soundm;
}
