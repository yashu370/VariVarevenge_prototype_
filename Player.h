# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>
# include "Character.h"

enum class State
{
	Default,
	DashNow,
	Invincible,
	Injured,
	Guard
};

enum class DamagedState {
	Default,
	nonDamaged,
	JustGuard,
	Dead,
	NonHit
};

class Player: public Character{
private:
	int Stamina;

	//移動中の判定を保存する
	Quad moving;

	State nowState;
	State postState;

	Stopwatch StaminaTimer;

	Stopwatch DefaultCooldownTimer;

	Stopwatch GuardIntervalTimer;

	void movingSet(Vec2&);
	void move(Vec2) override;




public:
	Player();

	bool CanMove();
	bool DashAble();

	State getState() const;
	void setState(State);

	int getStamina() const;
	void setStamina(int);

	Circle getCollision();
	Quad getMoveCollision();

	//指定した値だけ移動

	void update(double deltatime,Vec2 MoveDir,bool DashButtonPressed,bool GuardButtonpress);

	//描画
	void draw() const override;

	void Damage(int value, DamagedState& hitState);

};
