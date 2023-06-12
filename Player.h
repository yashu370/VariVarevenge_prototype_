# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>

class Player {
private:
	int HP;
	int maxHP;
	int Stamina;
	Vec2 Pos;
	double rad = 20;

	//移動中の判定を保存する
	Quad moving;

	void movingSet(Vec2&);
public:
	Player();


	Vec2 getPos() const;
	void setPos(Vec2);

	int getHP() const;
	void setHP(int);

	int getmaxHP() const;
	void setmaxHP(int);

	int getStamina() const;
	void setStamina(int);

	Circle getCollision();

	//指定した値だけ移動
	void move(Vec2);

	void update();

	//描画
	void draw() const;

};
