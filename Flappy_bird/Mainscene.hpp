#pragma once
#include "bird.hpp"

class Mainscene : public MyApp {
public:
	Mainscene(const InitData& init)
		: IScene(init) {};
	void Update() override;
	void draw() override;
};

