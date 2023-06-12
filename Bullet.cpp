﻿# include "Bullet.h"

Bullet::Bullet(Circle c,Vec2 velo) : Circle(c){
	m_velocity = velo;
}

Vec2 Bullet::getVelocity() { return m_velocity; }
void Bullet::setVelocity(Vec2 velo) { m_velocity = velo; }

void Bullet::update(const float time) {
	x += time * m_velocity.x;
	y += time * m_velocity.y;
}