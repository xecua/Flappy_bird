// #include <HamFramework.hpp>
#include "Bird.hpp"
#include "Pole.hpp"

void Main(){

	Graphics::SetBackground(ColorF(0.8,0.9,1.0));

	Bird player;

	const Font font(50);

	Array<std::unique_ptr<Pole>> poles;
	
	poles.emplace_back(new Pole());

	// Pole pole;

	long long score = 0;

	int counter = 0;

	Window::Resize(width, height);

	while (System::Update()) {
		// debug info
		ClearPrint();
		Print << player.getPos();
		Print << player.getVel();
		Print << Format(U"Score:",score);

		// player
		player.update();
		player.draw();

		// 新規Poleの追加
		if (++counter == 130) {
			poles.emplace_back(new Pole());
			counter = 0;
		}

		// pole
		if (!poles.isEmpty()) {
			if (!player.isGameOver()) {
				for (auto& p : poles) {
					p->update();
				}
			}
			for(auto& p:poles){
				p->draw();
			}
			if (poles[0]->getPos().x == 0 && !poles[0]->contain(player.getRect())) {
				score++;
				poles.pop_front();
			}
		}

		//pole.draw();
		//player.hitCheck(pole);
		

		// Gameover
		if (player.isGameOver()) {
			Print << U"Gameover!";
		}
	}
}

/* ここからやりたいこと
・ ゲームオーバーからリセットした場合に初期位置に戻す
・ Poleの無限生成
・スコア機能の実装
*/