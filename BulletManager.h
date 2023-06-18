# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>

# include "Bullet.h"

class BulletManager {
private:
	Array<Bullet> Bullets;
	int assignID=0;
public:
	void AddBullet(Bullet);
	void update(const double time);
	const void draw();

	//Circleに当たったかチェック&当たった弾のIDを格納
	bool intersectCircleCheck(Circle,Array<Bullet>& hitBullet);
	bool intersectQuadCheck(Quad, Array<Bullet>& hitBullet);

	void deleteBullet(Array<Bullet>&);
	//指定したIDの弾を削除する。

};
