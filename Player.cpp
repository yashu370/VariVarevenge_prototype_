# include "Player.h"

Player::Player() {
	setPos(Vec2(800,800));
	setRad(150);
	Stamina = 1;
	nowState = State::Default;
}

void Player::movingSet(Vec2& move) {
	Rect rect{ int(getPos().x),int(getPos().y - getRad()), int(move.length()+getRad()), int(2 * getRad())};
	moving.set(rect.rotatedAt(getPos(), move.getAngle() - 90_deg));
}

//本当に使う？
bool Player::CanMove() {
	if (nowState == State::DashNow) {
		return false;
	}
	else {
		return true;
	}
}

bool Player::DashAble() {
	if (getStamina() > 0) {
		return true;
	}
	else {
		return false;
	}
}


State Player::getState() const { return nowState; }
void Player::setState(State a) { nowState = a; }


Circle Player::getCollision() { return Circle{ getPos(),getRad() }; }
Quad Player::getMoveCollision() { return moving; }


void Player::move(Vec2 value) {
	movingSet(value);
	setPos(getPos()+value);
}

void Player::update(double deltatime,Vec2 MoveDir, bool DashButtonPressed,bool GuardSwitchPress) {



	//前の状態の記録
	postState = nowState;

	//プレイヤー移動処理
	const double speed = 40;
	const double dashspeed = 1000;
	//スタミナ回復時間
	const int StaminaRecoverTime = 600;//ms
	//被弾時無敵時間
	const int InjuredInvicibleTime = 1000;
	const int SuccessGurdInvincibleTime = 300;
	//ガードタイマー
	const int GuardMinTime = 220;



	//スタミナ回復タイマー処理
	if (Stamina == 0 && !StaminaTimer.isRunning()) {
		StaminaTimer.start();
	}
	else if (Stamina == 0 && StaminaTimer.ms() > StaminaRecoverTime) {
		setStamina(1);
		StaminaTimer.reset();
	}

	//ステートごとの処理
	switch (nowState)
	{
	case State::Default:
		//被弾処理は別メソッドで

		//ガード処理、ガードしたら
		if (GuardSwitchPress && !GuardIntervalTimer.isRunning()) {
			GuardIntervalTimer.start();
			nowState = State::Guard;
			break;
		}

		//ダッシュ処理　入力があるかつダッシュできる
		if (!MoveDir.isZero() && DashAble()&&DashButtonPressed) {
			//状態を変更
			nowState = State::DashNow;
			//ダッシュ移動(方向×距離)
			move(MoveDir * dashspeed);

			Stamina--;

		}
		else {
			if (getStamina() == 0) {
				move(MoveDir * speed/3);
			}
			else {
				move(MoveDir * speed);
			}
		}
		break;
	case State::DashNow:
		nowState = State::Default;
		break;
	case State::Invincible:
		move(MoveDir * speed);

		if (DefaultCooldownTimer.ms()>InjuredInvicibleTime) {
			DefaultCooldownTimer.reset();
			nowState = State::Default;
		}
		if (DefaultCooldownTimer.ms() > SuccessGurdInvincibleTime) {
			DefaultCooldownTimer.reset();
			nowState = State::Default;
		}

		break;
	case State::Injured:
		nowState = State::Invincible;
		DefaultCooldownTimer.start();
		break;
	case State::Guard:
		//被弾処理は別メソッドで(パリィ)
		//最少ガード時間以下だと継続
		if (!GuardSwitchPress &&GuardIntervalTimer.ms() > GuardMinTime) {
			GuardIntervalTimer.reset();
			nowState = State::Default;
		}

		break;

	default:
		break;
	}
}

void Player::draw() const {

	switch (nowState)
	{
	case State::Default:
		if (getStamina() == 0) {
			Circle{ getPos(),getRad() }.draw(Palette::Red);

		}
		else {
			Circle{ getPos(),getRad() }.draw(Palette::Yellow);

		}
		break;
	case State::DashNow:
		Circle{ getPos(),getRad() }.draw(Palette::Yellow);
		moving.draw(Palette::Yellow);
		break;
	case State::Invincible:
		Circle{ getPos(),getRad() }.draw(ColorF(1.0,1.0,1.0,0.3));
		break;
	case State::Injured:
		Circle{ getPos(),getRad() }.draw(Palette::Red);
		break;
	case State::Guard:
		Circle{ getPos(),getRad() }.draw(Palette::Yellowgreen);
		break;
	default:
		break;
	}

}


void Player::Damage(int value,DamagedState& hitState) {

	//パリィ時間
	const int GuardPaliyTime = 40;
	//ガード時(ノットパリィのダメージ軽減率)
	const double GuardDamageReductionRatio = 0.3;

	switch (nowState)
	{
	case State::Default:
		hitState = DamagedState::Default;
		nowState = State::Injured;
		break;
	case State::DashNow:
		hitState = DamagedState::nonDamaged;
		value = 0;
		break;
	case State::Invincible:
		hitState = DamagedState::nonDamaged;
		value = 0;
		break;
	case State::Injured:
		//基本次フレームのplayer.updateでステートがInvincibleに変わるので呼ばれないはず？
		break;
	case State::Guard:
		if (GuardIntervalTimer.ms() < GuardPaliyTime) {
			//パリィ成功時の処理
			hitState = DamagedState::JustGuard;
			GuardIntervalTimer.reset();
			nowState = State::Default;
		}
		else {
			hitState = DamagedState::Default;
			value *= GuardDamageReductionRatio;
		}
		break;
	default:
		break;
	}
	setHP(getHP() - value);
}

int Player::getStamina() const { return Stamina; }
void Player::setStamina(int a) { Stamina = a; }

