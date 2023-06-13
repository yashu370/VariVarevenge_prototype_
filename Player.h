# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>
# include "Character.h"

class Player: public Character{
private:
	int Stamina;

	//移動中の判定を保存する
	Quad moving;

	void movingSet(Vec2&);
public:
	Player();

	int getStamina() const;
	void setStamina(int);

	Circle getCollision();

	//指定した値だけ移動
	void move(Vec2) override;

	void update() override;

	//描画
	void draw() const override;

};
