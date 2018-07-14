#pragma once


class objects
{
protected:
	RectF rect;
	const bool collision;
public:
	objects(const RectF& r, bool col = false)
		: rect(r), collision(col) {}
	virtual void Update() {};
	virtual void draw() {
		rect.draw(Palette::Green);
	}

	virtual void move(Vec2& v) {
		rect.pos += v;
	}

	virtual Vec2& getPos() const {
		return rect.pos;
	}

	virtual RectF& getRect() const {
		return rect;
	}

	virtual bool iscollision() const {
		return collision;
	}

	// ~objects();
};

