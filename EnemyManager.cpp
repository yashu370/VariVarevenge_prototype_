# include "EnemyManager.h"


EnemyManager::EnemyManager(BulletManager *a) {
	enemy.setRad(300.0);
	enemy.setPos(Vec2(0, 0));
	BulletController = a;
	BombTimer.start();
}

Vec2 EnemyManager::getEnemyPos() const { return enemy.getPos(); }

void EnemyManager::update(double deltatime,Vec2 PlayerPos) {

	const int EnemySpeed = 200;

	const int BombCount = 1200;

	if (BombTimer.ms() > BombCount) {
		BombTimer.restart();
		Bomb(PlayerPos);
	}

	BulletController->update(deltatime);
}

void EnemyManager::draw() const {
	enemy.draw();
	BulletController->draw();
}

void EnemyManager::Bomb(Vec2 dir) {
	const int BulletSpeed = 900;

	const Vec2 A = Vec2(BulletSpeed, 0);
	double DefaultDirection = dir.getAngle();
	Print << A;

	for (int i = 0; i < 8; i++) {
		BulletController->AddBullet(Bullet{ Circle{enemy.getPos(),100},A.rotated(DefaultDirection + Math::QuarterPi +i * Math::TwoPi / 8) });
	}

}
