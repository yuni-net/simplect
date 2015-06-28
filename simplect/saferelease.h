#pragma once

namespace sim
{
	template<class X>
	void saferelease(X * p)
	{
		if (p)
		{
			p->Release(); p = NULL;
		}
	}
}