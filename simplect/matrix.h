#ifndef biringal2D_matrix_h_
#define biringal2D_matrix_h_

#include "includes.h"

namespace sim
{
	/*
	 * Š|‚¯Z‚Í’Êí‰‰Z‚Ì‚Æ‚«‚Æ“¯‚¶‡”Ô‚Å‹Lq‚µ‚Ä—Ç‚¢B
	*/
	class matrix
	{
	public:
		matrix();
		matrix(
			float _00, float _01, float _02,
			float _10, float _11, float _12,
			float _20, float _21, float _22 );
		matrix(const matrix & mat);
		matrix & operator=(const matrix & mat);
		float operator()(unsigned int y, unsigned int x);
		matrix operator*(const matrix & mat) const;
		matrix & operator*=(const matrix & mat);

		void x(float fValue);
		void y(float fValue);
		void z(float fValue);
		float  x() const;
		float  y() const;
		float  z() const;

		static matrix make_trans(float fVX, float fVY, float fVZ);
		static matrix make_scale(float fMagniX, float fMagniY, float fMagniZ);
		static matrix make_rotate(float fRadian);
		static matrix make_rotate(float fSin, float fCos);
		static matrix make_affine(const matrix & scale, const matrix & rotate, const matrix & trans);



	private:
		D3DXMATRIX matrix_;


	};
}

#endif