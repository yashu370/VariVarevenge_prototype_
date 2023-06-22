# include "Bullet.h"

Bullet::Bullet(Circle c,Vec2 velo) : Circle(c){
	m_velocity = velo;
}

Vec2 Bullet::getVelocity() const { return m_velocity; }

void Bullet::setVelocity(Vec2 velo) { m_velocity = velo; }

int Bullet::getID() const { return ID; }

void Bullet::setID(int val) { ID = val; }


void Bullet::update(const double time) {
	x += time * m_velocity.x;
	y += time * m_velocity.y;
}

bool Bullet::equalChack(const Bullet& it) const {
	return (it.getID()==this->getID());
}
