#pragma once
#include "objects.hpp"

class bird : public objects {
private:
	double velocity; // 縦方向だけでいい

public:
	bird(const RectF& r)
		: objects(r) {};
	void Update() override;
	// void draw() const override;

	void flap()

	//~bird();
};

