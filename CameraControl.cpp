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

void BackgroundDraw() {
	const int32 Framenum = 50;
	const int32 RectSize = 500;
	for (int32 i = -Framenum; i < Framenum; i++) {
		Line{ -Framenum * RectSize,i * RectSize,Framenum * RectSize,i * RectSize }.draw(3, ColorF(1, 0.3));
		Line{ i * RectSize,-Framenum * RectSize,i * RectSize,Framenum * RectSize }.draw(3, ColorF(1, 0.3));
	}

}
