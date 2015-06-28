#include <plate.h>
#include <window.h>

bool sim::plate::CreateRectanglePolygon(const DWORD FVF_2D)
{

	const int PolygonNum = 4;
	HRESULT hr;

	// 頂点バッファの作成
	hr = sim::window::GetDevice()->CreateVertexBuffer(sizeof(vertex2D)* PolygonNum, D3DUSAGE_WRITEONLY, FVF_2D, D3DPOOL_MANAGED, &vertbuff, NULL);
	if (FAILED(hr)) return false;

	vertex2D * pVtx = NULL;
	hr = vertbuff->Lock(0, 0, fw::pointer_cast<void **>(&pVtx), 0);
	if (FAILED(hr)) return false;

	pVtx[0].vtx = D3DXVECTOR3(top_left().coor().x(), top_left().coor().y(), 0.0f);
	pVtx[1].vtx = D3DXVECTOR3(top_right().coor().x(), top_right().coor().y(), 0.0f);
	pVtx[2].vtx = D3DXVECTOR3(bot_left().coor().x(), bot_left().coor().y(), 0.0f);
	pVtx[3].vtx = D3DXVECTOR3(bot_right().coor().x(), bot_right().coor().y(), 0.0f);

	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	pVtx[0].diffuse = D3DCOLOR_RGBA(top_left().color().r(), top_left().color().g(), top_left().color().b(), top_left().color().a());
	pVtx[1].diffuse = D3DCOLOR_RGBA(top_right().color().r(), top_right().color().g(), top_right().color().b(), top_right().color().a());
	pVtx[2].diffuse = D3DCOLOR_RGBA(bot_left().color().r(), bot_left().color().g(), bot_left().color().b(), bot_left().color().a());
	pVtx[3].diffuse = D3DCOLOR_RGBA(bot_right().color().r(), bot_right().color().g(), bot_right().color().b(), bot_right().color().a());


	vertbuff->Unlock();

	return true;
}