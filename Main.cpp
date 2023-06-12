# include <Siv3D.hpp> // OpenSiv3D v0.6.6
# include "Bullet.h"
# include "BulletManager.h"

void Main()
{
	
	Bullet a = Bullet{ Circle{20,20,10},Vec2{100,300} };
	Bullet b = Bullet{ Circle{10,10,3},Vec2{300,100} };
	Bullet c = Bullet{ Circle{10,10,30},Vec2{300,300} };
	BulletManager Good;
	Good.AddBullet(c);
	Good.AddBullet(a);
	Good.AddBullet(b);
	Good.AddBullet(a);
	Good.AddBullet(a);
	while (System::Update())
	{

		Good.AddBullet(a);
		Array<Bullet> hitBulletList;
		if (Good.intersectCheck(Circle{ Cursor::Pos(),100 }, hitBulletList)) {
			Good.deleteBullet(hitBulletList);
		}
		Good.update(Scene::DeltaTime());
		Good.draw();
		Circle{ Cursor::Pos(),100 }.draw();
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要です。
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/tutorial/
//
// Tutorial
// https://siv3d.github.io/tutorial/tutorial/
//
// Siv3D コミュニティへの参加（Discord などで気軽に質問や交流, 最新情報の入手ができます）
// https://siv3d.github.io/ja-jp/community/community/
//
// Siv3D User Community
// https://siv3d.github.io/community/community/
//
// 新機能の提案やバグの報告 | Feedback
// https://siv3d.github.io/ja-jp/develop/report/
//
// Sponsoring Siv3D
// https://github.com/sponsors/Reputeless
//
