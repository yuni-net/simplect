#pragma once

#include "includes.h"

namespace sim
{
	class mouse
	{
	public:
		enum ButtonID
		{
			button_left,
			button_middle,
			button_right
		};

		static int x();
		static int y();

		static int vx();
		static int vy();

		static int ax();
		static int ay();

		static int wheel_forward();		// �}�E�X�z�C�[���̍���̃t���[���̉�]��(�O�������v���X)
		static int wheel_backward();	// �}�E�X�z�C�[���̍���̃t���[���̉�]��(��������v���X)

		static bool freeing(ButtonID id);
		static bool pushed(ButtonID id);
		static bool pushing(ButtonID id);
		static bool clicked(ButtonID id);







		static mouse & GetInstance();
		mouse();
		bool init(LPDIRECTINPUT8 & diinterface, HWND windle);
		void update(HWND hwnd);
		~mouse();

	private:
		bool abButtonStatus[2/*old, now*/][3/*button_left, button_middle, button_right*/];
		bool bActiveIndex;
		int x_;
		int y_;
		int vx_;
		int vy_;
		int ax_;
		int ay_;
		int wheel_forward_;

		LPDIRECTINPUTDEVICE8 device;
	};
}