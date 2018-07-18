#pragma once
#include <Siv3D.hpp>

class Pole {
private:
	const int width = 800;
	const int height = 600;
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




