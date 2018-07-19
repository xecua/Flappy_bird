#include <deque>
#include "Bird.hpp"
#include "Pole.hpp"

void Main(){

	Graphics::SetBackground(ColorF(0.8,0.9,1.0));
	
    Window::SetTitle("Flppy Bird");

	const Font font(50);

	Bird player = Bird();

	std::deque<std::unique_ptr<Pole>> poles;
	
	poles.emplace_back(new Pole());

	long long score = 0;

	int counter = 0;

	Window::Resize(800, 600);

	while (System::Update()) {
		// debug info
		ClearPrint();
		Print << Format(U"Score:",score);

		player.update();
		player.draw();

		// 新規Poleの追加
		if (++counter == 150) {
			poles.emplace_back(new Pole());
			counter = 0;
		}

		// pole
		if (!poles.empty()) {
			if (!player.isGameOver()) {
				for (unsigned int i = 0; i < poles.size();i++) {
					poles[i]->update();
				}
			}
			for(unsigned int i = 0; i < poles.size(); i++){
				poles[i]->draw();
			}
			if (poles[0]->getPos().x == 0) {
				if(!poles[0]->contain(player.getRect())) score++;
				poles.pop_front();
			}
			player.hitCheck(*poles[0]);
		}

		// Gameover
		if (player.isGameOver()) {
			Print << U"Gameover!";
			poles.clear();
			counter = 0;
		}
	}
}
