# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>
# include "BulletManager.h"
# include "Character.h"

class EnemyManager {
private:
	BulletManager *BulletController;
	Character enemy;
public:
	EnemyManager(BulletManager *a);

	Vec2 getEnemyPos() const;

	void update(double deltatime);

	void draw() const;

};
