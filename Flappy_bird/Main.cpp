#include <Siv3D.hpp>

// #include <HamFramework.hpp>

#define width 800
#define height 600


class Pole {
private: 
	RectF under;
	RectF over;
	Vec2 pos;
public:
	Pole() {
		pos = { width, Random(0, height) };
		under.x = pos.x;
		under.y = pos.y + 100;
		under.w = 50;
		under.h = height - under.y;
		over.x = pos.x;
		over.y = 0;
		over.w = 50;
		over.h = pos.y - 100;
	}

	Vec2 getPos() const {
		return pos;
	}

	bool intersect(const Rect& shape) const {
		return (under.intersects(shape) || over.intersects(shape));
	}

	void update() {
		pos.x -= 5.0;
		under.x -= 5.0;
		over.x -= 5.0;
	}

	void draw() const {
		under.draw();
		over.draw();
	}

};



class Bird {
private:
	RectF rect;
	double velocity;
	bool gameover;
public:
	Bird() {
		rect = RectF(0.0, 1.0, 50.0, 50.0);
		velocity = 0.0;
		gameover = false;
	}

	void hitCheck(const Pole &pole) {
		if (pole.intersect(rect)) gameover = true;
	}

	void update() {

		if (rect.y < 0 || rect.y + rect.h > height) {
			gameover = true;
		}
		if(gameover) {
			rect.y = height - rect.h;
			velocity = 0;
			if (KeyZ.down()) {
				gameover = false;
				rect.y = 0.0;
			}
		}
		

		if (!gameover && KeySpace.down()) velocity -= 20.0;
		else velocity += 1.0;


		/*if ((rect.y + rect.h + velocity > height && velocity > 0.0)
			|| (rect.y + velocity < 0 && velocity < 0.0))  {
			velocity = 0;
		}*/
		rect.y += velocity;
	}
	void draw() {
		rect.draw(Palette::Yellow);
	}

	Vec2 getPos() const {
		return rect.center();
	}

	double getVel() const {
		return velocity;
	}

	bool isGameOver() const {
		return gameover;
	}
};




void Main(){

	Graphics::SetBackground(ColorF(0.8,0.9,1.0));

	Bird player;

	const Font font(50);

	Pole pole;

	Window::Resize(width, height);

	while (System::Update()) {
		ClearPrint();
		Print << player.getPos();
		Print << player.getVel();
		player.update();
		player.draw();
		pole.draw();
		Print << pole.getPos();
		player.hitCheck(pole);
		if(!player.isGameOver()) pole.update();

		if (player.isGameOver()) {
			Print << U"Gameover!";
		}
	}
}