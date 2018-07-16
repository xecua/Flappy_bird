#pragma once
#include "BaseObject.hpp"

class Pole :public BaseObject{
private:
	RectF under;
	RectF over;
public:
	Pole(const RectF r, const Vec2 v);

	bool intersect(const Rect& shape) const;

	void update() override;

	void draw() const override;

	bool contain(const RectF& shape) const;
};



