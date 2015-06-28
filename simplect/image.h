#ifndef biringal2D_image_h_
#define biringal2D_image_h_

#include "includes.h"
#include "saferelease.h"
//#include "window.h"
//#include "plate.h"

#include "matrix.h"
#include "image_data.h"

namespace sim
{
	class image
	{
	public:
		image(const char * path);
		image(const std::string & path);

		float x(float f32Value);
		float x() const;
		float y(float f32Value);
		float y() const;
		float magni(float f32Value);
		float magni() const;
		float degree(float f32Value);	// 回転角度。単位は度
		float degree() const;
		float radian(float f32Value);	// 回転角度。単位はラジアン
		float radian() const;
		float sincos(float fSin, float fCos);
		float sin() const;
		float cos() const;
		float cx(float f32Value);	// 回転や拡縮の中心となるx座標(画像の左上からの相対座標)
		float cx() const;
		float cy(float f32Value);	// 回転や拡縮の中心となるy座標(画像の左上からの相対座標)
		float cy() const;
		// rgba *********************************************
		/*
		 * 値は0.0f～1.0fの範囲で指定する
		 * マイナス値は全て0.0fとして処理される
		 * 1.0fを超えた値は全て1.0fとして処理される
		 *
		 */
		float bright_r(float val);
		float bright_r() const;
		float bright_g(float val);
		float bright_g() const;
		float bright_b(float val);
		float bright_b() const;
		float alpha(float val);
		float alpha() const;
		void  rgba(float r, float g, float b, float a);
		// **************************************************

		bool load(const char * path);
		bool load(const std::string & path);

		void image_data(const sim::image_data & target);

		virtual float width() const;
		virtual float height() const;
		uint base_width() const;
		uint base_height() const;

		bool draw() const;
		bool draw(const float basex, const float basey) const;
		bool draw_center() const;
		bool draw_center(const float basex, const float basey) const;



		image();
		~image();


	protected:
		float f32X;
		float f32Y;
		float f32Radian;
#if 0
		float f32Sin;	
		float f32Cos;
#endif
		float f32CX;	// 回転や拡縮の中心となるx座標(画像の左上からの相対座標)
		float f32CY;	// 回転や拡縮の中心となるy座標(画像の左上からの相対座標)
		float f32Magni;
		float r_;
		float g_;
		float b_;
		float a_;

		const sim::image_data * pImageData;
		bool ownership;

		void construct();
		void release();
		void Compute4dot(matrix & lt, matrix & rt, matrix & rb, matrix & lb, float basex, float basey) const;
		virtual void Compute_uv(top4 & uv) const;

	};

}


#endif