# include "EnemyManager.h"


EnemyManager::EnemyManager(BulletManager *a) {
	BulletController = a;
}

Vec2 EnemyManager::getEnemyPos() const { return enemy.getPos(); }

void EnemyManager::update(double deltatime) {
	BulletController->update(deltatime);
}

void EnemyManager::draw() const {
	enemy.draw();
	BulletController->draw();
}
