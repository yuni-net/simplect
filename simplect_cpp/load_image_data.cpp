#include "image_data.h"


#include "window.h"

bool sim::image_data::load(const char * path)
{
	if (vertbuff == NULL) return false;

	HRESULT hr;

	D3DXIMAGE_INFO info;
	hr = D3DXGetImageInfoFromFile(path, &info);
	if (FAILED(hr)) return false;
	Width = info.Width;
	Height = info.Height;

	saferelease(texture);

	hr = D3DXCreateTextureFromFileEx(
		::sim::window::GetDevice(),
		path,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		0,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		NULL,
		NULL,
		&texture);

	return bool(SUCCEEDED(hr));
}


bool sim::image_data::load(const std::string & path)
{
	return load(path.c_str());
}

