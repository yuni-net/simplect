#pragma once

namespace sim
{

	class color
	{
	public:
		void r(unsigned char v);
		void g(unsigned char v);
		void b(unsigned char v);
		void a(unsigned char v);
		unsigned char r();
		unsigned char g();
		unsigned char b();
		unsigned char a();

	private:
		unsigned char ucR;
		unsigned char ucG;
		unsigned char ucB;
		unsigned char ucA;
	};

}


