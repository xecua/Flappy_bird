#pragma once
#include "objects.hpp"
class Ground : public objects {
public:
	Ground(const Rect r)
		: objects(r,true);
};

