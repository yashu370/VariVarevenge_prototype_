# include <Siv3D.hpp> // OpenSiv3D v0.6.6
# include "Bullet.h"
# include "BulletManager.h"
# include "Player.h"

void Main()
{
	//gamapad
	size_t playerIndex = 0;
	//camera

	const Vec2 Center = { 300,400 };
	const double ScaleMinLength = 300.0;
	Camera2D camera{ Center,1.0 };

	Bullet a = Bullet{ Circle{20,20,10},Vec2{100,300} };
	Bullet b = Bullet{ Circle{10,10,3},Vec2{300,100} };
	BulletManager Good;
	Good.AddBullet(a);
	Good.AddBullet(b);

	Player player;

	while (System::Update())
	{
		ClearPrint();

		//入力管理
		double inputX = 0;
		double inputY = 0;
		Input inputA;

		if (const auto gamepad = Gamepad(playerIndex)) {
			inputX = gamepad.axes[0];
			inputY = gamepad.axes[1];
			inputA = gamepad.buttons[2];
		}
		//微細な入力は無視
		if (abs(inputX) < 0.1) { inputX = 0; }
		if (abs(inputY) < 0.1) { inputY = 0; }
		//絶対値が1以下になるようにする
		double InputAbs = pow(inputX, 2) + pow(inputY, 2);
		if ( InputAbs> 1) {
			inputX /= sqrt(InputAbs);
			inputY /= sqrt(InputAbs);
		}

		//キャラの移動
		player.move(15 * Vec2{ inputX, inputY });

		Array<Bullet> hitBulletList;
		if (Good.intersectCheck(player.getCollision(), hitBulletList)) {
			Good.deleteBullet(hitBulletList);
		}
		Good.update(Scene::DeltaTime());


		double ZoomValue = 1.0;

		if (ScaleMinLength > player.getPos().distanceFrom(Center)) {
			ZoomValue = 1.0;

		}
		else {
			ZoomValue = ScaleMinLength / player.getPos().distanceFrom(Center);
		}


		camera.update();
		{
			const auto t = camera.createTransformer();

			player.draw();
			Good.draw();
		}
		
		camera.setTargetCenter(Vec2((player.getPos().x + Center.x) / 2, (player.getPos().y + Center.y) / 2));
		camera.setTargetScale(ZoomValue);
		
		
		
	}
}
