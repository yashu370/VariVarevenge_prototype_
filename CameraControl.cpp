# include "CameraControl.h"
# include "Player.h"



void cameraControl(Camera2D& camera,const Vec2 playerPos,const Vec2 EnemyPos) {

	const double ScaleMinLength = 300.0;

	double ZoomValue = 1.0;

	if (ScaleMinLength > playerPos.distanceFrom(EnemyPos)) {
		ZoomValue = 1.0;

	}
	else {
		ZoomValue = ScaleMinLength / playerPos.distanceFrom(EnemyPos);
	}


	camera.setTargetCenter(Vec2((playerPos.x + EnemyPos.x) / 2, (playerPos.y + EnemyPos.y) / 2));
	camera.setTargetScale(ZoomValue);

}
