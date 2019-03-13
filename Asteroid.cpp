#include "Asteroid.h"

Asteroid::Asteroid() {
	width_ = 20;
	height_ = 20;

	//SetId();
}

Asteroid::Asteroid(SDLGame* game) : Container(game)
{
	Asteroid();

	srand(time(0));
	position_ = Vector2D(0, 0);
	velocity_ = Vector2D(0, 0);

	//setId();
}

Asteroid::~Asteroid() {}