#pragma once
#include <Siv3D.hpp>
#define width 800
#define height 600


class BaseObject{
protected:
	RectF rect;
	Vec2 velocity;
public:
	BaseObject(const RectF r,const Vec2 v)
		:rect(r),velocity(v) {}

	virtual void update() {
		rect.pos += velocity;
	}
	virtual void draw() const {
		rect.draw();
	}

	virtual Vec2 getPos() {
		return rect.pos;
	}

	virtual RectF getRect() {
		return rect;
	}

};

