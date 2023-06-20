# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>
# include "BulletManager.h"
# include "Player.h"

class EnemyManager {
private:
	BulletManager *BulletController;
	Character enemy;

	Stopwatch BombTimer;
public:
	EnemyManager(BulletManager *a);

	Vec2 getEnemyPos() const;

	void update(double deltatime,Vec2 PlayerPos);

	void draw() const;

	void Bomb(Vec2 dir);
};
