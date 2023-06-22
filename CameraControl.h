# pragma once
//# define NO_S3D_USING
# include <Siv3D.hpp>
# include "Player.h"

enum class TimeSpeedState {
	Default,
	Stop,
	Slow
};

void cameraControl(Camera2D& camera, const Vec2 playerPos,const Vec2 EnemyPos);
void BackgroundDraw();
