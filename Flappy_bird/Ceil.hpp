#pragma once
#include "objects.hpp"

class Ceil : public objects {
public:
	Ceil()
		:objects(RectF(Vec2(0,0),Window::Width,1),true) ;
};
