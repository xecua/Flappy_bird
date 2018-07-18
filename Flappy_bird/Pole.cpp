#include "Pole.hpp"

Pole::Pole() {
	pos = { width, Random(0, height) };
	under.x = width;
	under.y = pos.y + 100;
	under.w = 50;
	under.h = height - under.y;
	over.x = width;
	over.y = 0;
	over.w = 50;
	over.h = pos.y - 100;
	velocity = { -10,0 };
}

bool Pole::intersect(const RectF& shape) const {
	return (under.intersects(shape) || over.intersects(shape));
}

void Pole::update(){
	pos += velocity;
	under.pos += velocity;
	over.pos += velocity;
}

void Pole::draw() const {
	under.draw();
	over.draw();
}

bool Pole::contain(const RectF& shape) const {
	return under.contains(shape) || over.contains(shape);
}

Vec2 Pole::getPos() const{
	return pos;
}