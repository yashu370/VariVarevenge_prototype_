# include "Player.h"

Player::Player() {
	setPos(Scene::Center());
}

void Player::movingSet(Vec2& move) {
	Rect rect{ int(getPos().x),int(getPos().y - getRad()), int(move.length()), int(2 * getRad())};
	moving.set(rect.rotatedAt(getPos(), move.getAngle() - 90_deg));
}



Circle Player::getCollision() { return Circle{ getPos(),getRad() }; }

void Player::move(Vec2 value) {
	movingSet(value);
	setPos(getPos()+value);
}

void Player::update() {

}

void Player::draw() const {
	moving.draw();
	Circle{ getPos(),getRad() }.draw();
}


int Player::getStamina() const { return Stamina; }
void Player::setStamina(int a) { Stamina = a; }
