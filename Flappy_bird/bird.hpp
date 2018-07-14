#pragma once
#include "objects.hpp"

class bird : public objects {
private:
	double velocity; // c•ûŒü‚¾‚¯‚Å‚¢‚¢

public:
	bird(const RectF& r)
		: objects(r) {};
	void Update() override;
	// void draw() const override;

	void flap()

	//~bird();
};

