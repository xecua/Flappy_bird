#include "Pole.hpp"
#include "Bird.hpp"


Bird::Bird() {
	rect = Rect(0, 0, 50, 50);
	velocity = { 0,0 };
	gameover = false;
}

void Bird::hitCheck(const Pole& pole) {
	if (pole.intersect(rect)) gameover = true;
}

void Bird::update() {
	if (rect.y < 0 || rect.y + rect.h > height) {
		gameover = true;
	}
	if (gameover) {
		rect.y = height - rect.h;
		velocity.y = 0;
		if (KeyZ.down()) {
			gameover = false;
			rect.y = 0.0;
		}
	}


	if (!gameover && KeySpace.down()) velocity.y -= 20.0;
	else velocity.y += 1.0;


	rect.pos += velocity;
}

void Bird::draw() const {
	rect.draw(Palette::Yellow);
}

double Bird::getVel() const {
	return velocity.y;
}

bool Bird::isGameOver() const {
	return gameover;
}

Vec2 Bird::getPos() const {
	return rect.pos;
}

RectF Bird::getRect() const {
	return rect;
}
