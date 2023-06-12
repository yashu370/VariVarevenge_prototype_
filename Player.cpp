# include "Player.h"

Player::Player() {
	Pos = Scene::Center();
}

void Player::movingSet(Vec2& move) {
	Rect rect{ int(Pos.x),int(Pos.y - rad), int(move.length()), int(2 * rad) };
	moving.set(rect.rotatedAt(Pos, move.getAngle() - 90_deg));
}



Circle Player::getCollision() { return Circle{ Pos,rad }; }

void Player::move(Vec2 value) {
	movingSet(value);
	Pos += value;
}

void Player::update() {

}

void Player::draw() const {
	moving.draw();
	Circle{ Pos,rad }.draw();
}


Vec2 Player::getPos() const { return Pos; }
void Player::setPos(Vec2 a) { Pos = a; }
int Player::getHP() const { return HP; }
void Player::setHP(int a) { HP = a; }
int Player::getmaxHP() const { return maxHP; }
void Player::setmaxHP(int a) { maxHP = a; }
int Player::getStamina() const { return Stamina; }
void Player::setStamina(int a) { Stamina = a; }
