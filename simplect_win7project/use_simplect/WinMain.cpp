#include <simplect.h>

struct soundID
{
	enum
	{
		bgm,
		ok,
		num
	};
};

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{

	sim::manager mymanager;
	if (mymanager.init() == false) return -1;

	auto & soundm = mymanager.get_sound_manager();
	soundm.reserve4ID_path(soundID::num);
	soundm.register_ID_path(soundID::bgm, "bgm.wav");
	soundm.register_ID_path(soundID::ok, "ok.wav");

	sim::image azu;
	azu.load("saturn.png");

	sim::unique_sound bgm(soundID::bgm);
	bgm.reloop();

	sim::se ok(soundID::ok);

	while (fw::window::processage() )
	{
		if (mymanager.clear() == false) return -1;

		if (sim::key::pushed(DIK_SPACE))
		{
			ok.play();
		}

		// 移動 ****************************************************
		const float fMoveSpeed = 4.0f;

		if (sim::key::pushing(DIK_UP))
		{
			azu.y(azu.y() - fMoveSpeed);
		}

		if (sim::key::pushing(DIK_RIGHT))
		{
			azu.x(azu.x() + fMoveSpeed);
		}

		if (sim::key::pushing(DIK_DOWN))
		{
			azu.y(azu.y() + fMoveSpeed);
		}

		if (sim::key::pushing(DIK_LEFT))
		{
			azu.x(azu.x() - fMoveSpeed);
		}
		// ***********************************************************

		// 回転 ******************************************************
		const float fRotSpeed = 0.2f;

		//memo DirectX9版では、ラジアンの値を引いていくと右向きに回った

		if (sim::key::pushing(DIK_Z))
		{
			azu.radian(azu.radian() - fRotSpeed);
		}
		if (sim::key::pushing(DIK_X))
		{
			azu.radian(azu.radian() + fRotSpeed);
		}

		// ***********************************************************

		// 拡大縮小 **************************************************

		if (sim::key::pushing(DIK_C))
		{
			azu.magni(azu.magni() * 1.1f);
		}
		if (sim::key::pushing(DIK_V))
		{
			azu.magni(azu.magni() * 0.9f);
		}

		// ***********************************************************

		azu.draw_center();


		mymanager.update();
	}

	return 0;
}