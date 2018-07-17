#pragma once
#define width 600
#define height 800
#include <Siv3D.hpp>

class Pole {
private:
	RectF under;
	RectF over;
	Vec2 pos;
	Vec2 velocity;
public:
	Pole();

	bool intersect(const RectF& shape) const;

	Vec2 getPos() const;

	void update();

	void draw() const;

	bool contain(const RectF& shape) const;
};




