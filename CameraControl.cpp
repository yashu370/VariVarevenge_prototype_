# include "CameraControl.h"
# include "Player.h"

void cameraControl(Camera2D& camera,const Player player) {

	const Vec2 Center = { 300,400 };
	const double ScaleMinLength = 300.0;

	double ZoomValue = 1.0;

	if (ScaleMinLength > player.getPos().distanceFrom(Center)) {
		ZoomValue = 1.0;

	}
	else {
		ZoomValue = ScaleMinLength / player.getPos().distanceFrom(Center);
	}


	camera.setTargetCenter(Vec2((player.getPos().x + Center.x) / 2, (player.getPos().y + Center.y) / 2));
	camera.setTargetScale(ZoomValue);

}
