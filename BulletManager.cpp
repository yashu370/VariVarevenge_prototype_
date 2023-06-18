# include "BulletManager.h"

void BulletManager::AddBullet(Bullet it) {
	it.setID(assignID);
	assignID++;
	Bullets << it;
}

void BulletManager::update(const double time) {
	for (auto& it : Bullets) {
		it.update(time);
	}
	
}

const void BulletManager::draw() {
	for (const auto& it : Bullets) {
		it.draw();
	}
}

bool BulletManager::intersectCircleCheck(Circle my, Array<Bullet>& hitBullet) {
	bool flag = false;
	for (const auto& it : Bullets) {
		//当たったときはhitbulletに当たったものを格納する
		if (it.intersects(my)) {
			hitBullet << it;
			flag = true;
		}

	}
	//当たらなかったとき
	return flag;
}

bool BulletManager::intersectQuadCheck(Quad my, Array<Bullet>& hitBullet) {
	bool flag = false;
	for (const auto& it : Bullets) {
		//当たったときはhitbulletに当たったものを格納する
		if (it.intersects(my)) {
			hitBullet << it;
			flag = true;
		}

	}
	//当たらなかったとき
	return flag;
}


void BulletManager::deleteBullet(Array<Bullet>& hitBullet) {
	if (hitBullet.isEmpty()) { return; }
	Print << U"呼ばれた";
	for (auto it = Bullets.begin(); it != Bullets.end();)
	{
		//削除リストにあったかどうか
		bool flag = false;
		for (const auto&itt:hitBullet) {
			if (itt.equalChack(*it)) {
				flag = true;
			}
		}
		// 円がクリックされたらその地点を表す要素を削除
		if (flag)
		{
			// 現在のイテレータが指す要素を削除し、イテレータを進める
			it = Bullets.erase(it);
		}
		else
		{
			// イテレータを進める
			++it;
		}
	}

}
