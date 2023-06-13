# include <Siv3D.hpp> // OpenSiv3D v0.6.6
# include "Bullet.h"
# include "BulletManager.h"
# include "EnemyManager.h"
# include "CameraControl.h"

void Main()
{
	//gamapad
	size_t playerIndex = 0;
	//camera

	Camera2D camera{ Vec2{300,400},1.0};

	Bullet a = Bullet{ Circle{20,20,10},Vec2{100,300} };
	Bullet b = Bullet{ Circle{10,10,3},Vec2{300,100} };
	BulletManager Good;
	Good.AddBullet(a);
	Good.AddBullet(b);

	EnemyManager enemyControle(&Good);

	Player player;

	while (System::Update())
	{
		ClearPrint();

		//入力管理
		Vec2 inputDir;
		Input inputA;

		if (const auto gamepad = Gamepad(playerIndex)) {
			inputDir.x = gamepad.axes[0];
			inputDir.y = gamepad.axes[1];
			inputA = gamepad.buttons[2];
		}
		//微細な入力は無視
		if (abs(inputDir.x) < 0.1) { inputDir.x = 0; }
		if (abs(inputDir.y) < 0.1) { inputDir.y = 0; }
		//絶対値が1以下になるようにする
		if (inputDir.length() > 1) {
			inputDir.normalize();
		}


		//キャラの移動]

		Array<Bullet> hitBulletList;
		if (Good.intersectCheck(player.getCollision(), hitBulletList)) {
			//衝突時に行われる処理
			Good.deleteBullet(hitBulletList);
		}

		player.update(Scene::DeltaTime(),inputDir);
		enemyControle.update(Scene::DeltaTime());


		cameraControl(camera, player.getPos(), enemyControle.getEnemyPos());


		camera.update();
		{
			const auto t = camera.createTransformer();

			player.draw();
			enemyControle.draw();
		}
		
		
		
		
	}
}
