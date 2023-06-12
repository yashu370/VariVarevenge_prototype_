#pragma once
# include <Siv3D.hpp>

class Bullet : public Circle{
private:
	Vec2 m_velocity;
public:
	Bullet(Circle,Vec2);

	Vec2 getVelocity();
	void setVelocity(Vec2);

	void update(const float time);
	
};
