#include "image.h"
#include "includes.h"
#include "cast.h"



#include "window.h"

bool sim::image_data::CreateRectanglePolygon(const top4 & xy, const top4 & uv, const diffuse & rgba, const float basex, const float basey) const
{
	HRESULT hr;

	vertex2D * pVtx = NULL;
	hr = vertbuff->Lock(0, 0, fw::pointer_cast<void **>(&pVtx), 0);
	if (FAILED(hr)) return false;

	pVtx[0].vtx = D3DXVECTOR3(xy.lt.x(), xy.lt.y(), 0.0f);
	pVtx[1].vtx = D3DXVECTOR3(xy.rt.x(), xy.rt.y(), 0.0f);
	pVtx[2].vtx = D3DXVECTOR3(xy.lb.x(), xy.lb.y(), 0.0f);
	pVtx[3].vtx = D3DXVECTOR3(xy.rb.x(), xy.rb.y(), 0.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].diffuse = D3DCOLOR_RGBA(rgba.red, rgba.green, rgba.blue, rgba.alpha);
	pVtx[1].diffuse = D3DCOLOR_RGBA(rgba.red, rgba.green, rgba.blue, rgba.alpha);
	pVtx[2].diffuse = D3DCOLOR_RGBA(rgba.red, rgba.green, rgba.blue, rgba.alpha);
	pVtx[3].diffuse = D3DCOLOR_RGBA(rgba.red, rgba.green, rgba.blue, rgba.alpha);

	pVtx[0].tex = D3DXVECTOR2(uv.lt.x(), uv.lt.y());
	pVtx[1].tex = D3DXVECTOR2(uv.rt.x(), uv.rt.y());
	pVtx[2].tex = D3DXVECTOR2(uv.lb.x(), uv.lb.y());
	pVtx[3].tex = D3DXVECTOR2(uv.rb.x(), uv.rb.y());

	vertbuff->Unlock();

	return true;

}
