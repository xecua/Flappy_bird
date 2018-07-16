#pragma once
#include "BaseObject.hpp"
#include "Pole.hpp"

class Bird : public BaseObject{
private:
	bool gameover;
public:
	Bird(const RectF r, const Vec2 v);

	void hitCheck(const Pole &pole);

	void update() override;

	void draw() const override;

	double getVel() const;

	bool isGameOver() const;

};
