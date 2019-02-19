#pragma once

#include <time.h>

#include "Container.h"

class Asteroid : public Container {
public:
	Asteroid();
	Asteroid(SDLGame* game);
	virtual ~Asteroid();

	int getGenerations() { return generations_; }
	void setGenerations(int g) { generations_ = g; }

private:
	int generations_ = 3;
};

