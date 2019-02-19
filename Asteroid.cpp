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
	position_ = Vector2D(rand() % game->getWindowHeight(), rand() % game->getWindowWidth());
	velocity_ = Vector2D(rand() % 3, rand() % 3);

	//setId();
}

Asteroid::~Asteroid() {}