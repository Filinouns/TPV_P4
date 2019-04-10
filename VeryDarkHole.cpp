#include "VeryDarkHole.h"

VeryDarkHole::VeryDarkHole() {
	width_ = 50;
	height_ = 50;
}

VeryDarkHole::VeryDarkHole(SDLGame* game) : Container(game) {
	VeryDarkHole();

	position_ = Vector2D(0, 0);
	velocity_ = Vector2D(0, 0);
}

VeryDarkHole::~VeryDarkHole() {}