#include "Title.hpp"


Title::Title(const InitData& init)
	: IScene(init) {}

void Title::update() {
	// Z��������MainScene��
	if (KeyZ.down()) {
		changeScene(U"Mainscene");
	}
}

void Title::draw() const {
	FontAsset(U"MainFont")(U"po").drawAt(Window::Center(), Palette::Black);
}