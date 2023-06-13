# include "Player.h"

Player::Player() {
	setPos(Scene::Center());
}

void Player::movingSet(Vec2& move) {
	Rect rect{ int(getPos().x),int(getPos().y - getRad()), int(move.length()), int(2 * getRad())};
	moving.set(rect.rotatedAt(getPos(), move.getAngle() - 90_deg));
}


bool Player::playerCanMove() {
	//未実装
	return true;
}


State Player::getState() const { return nowState; }
void Player::setState(State a) { nowState = a; }


Circle Player::getCollision() { return Circle{ getPos(),getRad() }; }

void Player::move(Vec2 value) {
	movingSet(value);
	setPos(getPos()+value);
}

void Player::update(double deltatime,Vec2 MoveDir) {
	//前の状態の記録
	postState = nowState;

	//プレイヤー移動処理
	const double speed = 15;
	if (playerCanMove()) {
		move(MoveDir * speed);
	}


	switch (nowState)
	{
	case State::Default:
		break;
	case State::Dash:
		break;
	case State::Invincible:
		break;
	case State::injured:
		break;
	default:
		break;
	}
}

void Player::draw() const {
	moving.draw();
	Circle{ getPos(),getRad() }.draw();
}


int Player::getStamina() const { return Stamina; }
void Player::setStamina(int a) { Stamina = a; }
