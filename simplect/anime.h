#ifndef anime_h_
#define anime_h_

#include "image.h"
#include "canimer.h"

namespace sim
{

	class anime :private image
	{
	public:
		anime(const char * path, uint pieceWidth, uint pieceHeight, uint enableNum);
		anime(const std::string & path, uint pieceWidth, uint pieceHeight, uint enableNum);

		using image::x;
		using image::y;
		using image::magni;
		using image::degree;
		using image::radian;
		using image::sin;
		using image::cos;
		using image::cx;
		using image::cy;
		using image::bright_r;
		using image::bright_g;
		using image::bright_b;
		using image::alpha;
		using image::rgba;
		// Do not using image::load;
		// Do not using image::image_data
		// Do not using image::width;
		// Do not using image::height;
		using image::base_width;
		using image::base_height;
		using image::draw;
		using image::image;
		using image::~image;

		bool load(const char * path, uint pieceWidth, uint pieceHeight, uint enableNum);
		bool load(const std::string & path, uint pieceWidth, uint pieceHeight, uint enableNum);

		bool image_data(const sim::image_data & target, uint pieceWidth, uint pieceHeight, uint enableNum);

		float width() const;
		float height() const;

		void animation();
		void animation_once();
		void resistor(int v);
		void replay();
		bool ifFinalFrame();
		void set(int nNo);
		int maxNo();




		anime();
	protected:

		canimer cnt;
		int pieceWidth;
		int pieceHeight;


		void animeset(uint pieceWidth, uint pieceHeight, uint enableNum);
		/* @override */ void Compute_uv(top4 & uv) const;
	};

}

#endif