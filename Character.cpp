# include "Character.h"

Character::Character() {
	Pos = Scene::Center();
}




Circle Character::getCollision() { return Circle{ Pos,rad }; }

void Character::move(Vec2 value) {
	Pos += value;
}

void Character::update(double deltatime) {

}

void Character::draw() const {
	Circle{ Pos,rad }.draw();
}


Vec2 Character::getPos() const { return Pos; }
void Character::setPos(Vec2 a) { Pos = a; }
int Character::getHP() const { return HP; }
void Character::setHP(int a) { HP = a; }
int Character::getmaxHP() const { return maxHP; }
void Character::setmaxHP(int a) { maxHP = a; }
double Character::getRad() const { return rad; }
void Character::setRad(double a) { rad = a; }

