# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>

class Character {
private:
	int HP;
	int maxHP;
	Vec2 Pos;
	double rad = 20;


public:
	Character();


	Vec2 getPos() const;
	void setPos(Vec2);

	int getHP() const;
	void setHP(int);

	int getmaxHP() const;
	void setmaxHP(int);

	double getRad() const;
	void setRad(double);

	Circle getCollision();

	//指定した値だけ移動
	virtual void move(Vec2);

	virtual void update(double deltatime);

	//描画
	virtual void draw() const;

};
