#pragma once
#include "Pole.hpp"

class Bird{
private:
	const int width = 800;
	const int height = 600;
	RectF rect;
	Vec2 velocity;
	bool gameover;
public:
	Bird();

	void hitCheck(const Pole &pole);

	void update();

	void draw() const;

	double getVel() const;

	bool isGameOver() const;

	Vec2 getPos() const;

	RectF getRect() const;

};

