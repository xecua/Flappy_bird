#include "Pole.hpp"

Pole::Pole(const RectF r, const Vec2 v) {
	BaseObject(r, v);
	
	// pos = { width, Random(0, height) };
	under.x = rect.x;
	under.y = rect.y + 100;
	under.w = 50;
	under.h = height - under.y;
	over.x = rect.x;
	over.y = 0;
	over.w = 50;
	over.h = rect.y - 100;
}

bool Pole::intersect(const Rect& shape) const {
	return (under.intersects(shape) || over.intersects(shape));
}

void Pole::update(){
	rect.pos -= velocity;
	under.pos -= velocity;
	over.pos -= velocity;
}

void Pole::draw() const {
	under.draw();
	over.draw();
}

bool Pole::contain(const RectF& shape) const {
	return under.contains(shape) || over.contains(shape);
}
