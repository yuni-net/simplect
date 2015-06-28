#include <window.h>

bool sim::window::SetViewPort()
{
	D3DVIEWPORT9 vp;
	vp.X = 0;
	vp.Y = 0;
	vp.Width = prepara.BackBufferWidth;
	vp.Height = prepara.BackBufferHeight;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;
	HRESULT hr = device->SetViewport(&vp);
	if(FAILED(hr) )
	{
		#ifdef MIE_MIENDOW_CREATE_POP_UP_
			fw::popup("failed to set view port");
		#endif
		return false;
	}

	return true;
}