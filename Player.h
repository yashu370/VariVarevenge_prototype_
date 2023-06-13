# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>
# include "Character.h"

enum class State
{
	Default,
	Dash,
	Invincible,
	injured
};

class Player: public Character{
private:
	int Stamina;

	//移動中の判定を保存する
	Quad moving;

	State nowState;
	State postState;

	Stopwatch a;


	void movingSet(Vec2&);
	void move(Vec2) override;
public:
	Player();

	bool playerCanMove();


	State getState() const;
	void setState(State);

	int getStamina() const;
	void setStamina(int);

	Circle getCollision();

	//指定した値だけ移動

	void update(double deltatime,Vec2 MoveDir);

	//描画
	void draw() const override;


};
