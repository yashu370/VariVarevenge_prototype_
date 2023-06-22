# include <Siv3D.hpp> // OpenSiv3D v0.6.6
# include "Bullet.h"
# include "BulletManager.h"
# include "EnemyManager.h"
# include "CameraControl.h"



void Main()
{
	Window::Resize(1900, 1020);

	//gamapad
	size_t playerIndex = 0;
	//camera

	Camera2D camera{ Vec2{300,400},1.0};

	Bullet a = Bullet{ Circle{20,20,10},Vec2{100,300} };
	Bullet b = Bullet{ Circle{10,10,3},Vec2{300,100} };
	BulletManager Good;

	EnemyManager enemyControle(&Good);

	Player player;

	Stopwatch TimeSpeedControleTimer;
	const int JustGuardTimeLength = 1000;
	

	TimeSpeedState nowTimeSpeed = TimeSpeedState::Default;


	while (System::Update())
	{
		ClearPrint();

		//入力管理
		Vec2 inputDir;
		Input inputA;
		Input inputR;

		if (const auto gamepad = Gamepad(playerIndex)) {
			inputDir.x = gamepad.axes[0];
			inputDir.y = gamepad.axes[1];
			inputA = gamepad.buttons[2];
			inputR = gamepad.buttons[4];
		}
		//微細な入力は無視
		if (abs(inputDir.x) < 0.1) { inputDir.x = 0; }
		if (abs(inputDir.y) < 0.1) { inputDir.y = 0; }
		//絶対値が1以下になるようにする
		if (inputDir.length() > 1) {
			inputDir.normalize();
		}

		//時間停止魔法
		double DeltaTime=Scene::DeltaTime();

		switch (nowTimeSpeed)
		{
		case TimeSpeedState::Default:
			break;
		case TimeSpeedState::Stop:
			DeltaTime = Scene::DeltaTime() / 10;
			if (TimeSpeedControleTimer.ms() > JustGuardTimeLength) {
				TimeSpeedControleTimer.reset();
				nowTimeSpeed = TimeSpeedState::Default;
			}
			break;
		case TimeSpeedState::Slow:
			break;
			DeltaTime = Scene::DeltaTime() / 3;
		default:
			break;
		}



		//キャラの移動]

		player.update(DeltaTime, inputDir, inputA.down(), inputR.pressed());


		enemyControle.update(DeltaTime, player.getPos());

		//被弾処理
		Array<Bullet> hitBulletList;//当たった球のインスタンスを入れる場所

		DamagedState nowFrameDamagedState = DamagedState::NonHit;

		
		if (Good.intersectQuadCheck(player.getMoveCollision(), hitBulletList) && player.getState() == State::DashNow) {
			//ダッシュ時に当たった弾、ダッシュ時弾処理
			Good.deleteBullet(hitBulletList);
			player.setStamina(1);
			Print << U"呼ばれた";
		}
		else {
			//一旦配列リセット
			hitBulletList.clear();
		}


		if (Good.intersectCircleCheck(player.getCollision(), hitBulletList)) {
			//衝突時に行われる処理
			Good.deleteBullet(hitBulletList);
			player.Damage(1, nowFrameDamagedState);
		}

		//時間処理
		switch (nowFrameDamagedState)
		{
		case DamagedState::Default:
			break;
		case DamagedState::nonDamaged:
			break;
		case DamagedState::JustGuard:
			//ジャスガ(パリィ)を決めたとき…
			nowTimeSpeed = TimeSpeedState::Stop;
			TimeSpeedControleTimer.start();
			Print << U"バーか";
			break;
		case DamagedState::Dead:
			break;
		case DamagedState::NonHit:
			break;
		default:
			break;
		}
		

		Print << int(player.getState());


		cameraControl(camera, player.getPos(), enemyControle.getEnemyPos());


		camera.update();
		{
			const auto t = camera.createTransformer();
			BackgroundDraw();
			player.draw();
			enemyControle.draw();
		}
		
		
		
		
	}
}
