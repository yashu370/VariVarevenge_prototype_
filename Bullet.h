#pragma once
# include <Siv3D.hpp>

class Bullet : public Circle{
private:
	int ID = -1;
	Vec2 m_velocity;
public:
	Bullet(Circle,Vec2);

	Vec2 getVelocity() const;

	void setVelocity(Vec2);

	int getID() const;

	void setID(int);

	void update(const double time);
	//指定された秒数×速さだけ弾の座標を移動

	bool equalChack(const Bullet&) const;
	
};
