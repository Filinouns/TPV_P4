#pragma once

#include "PhysicsComponent.h"
#include "Asteroid.h"

class FighterAsteroidCollision : public PhysicsComponent {
public:
	FighterAsteroidCollision();
	virtual ~FighterAsteroidCollision();
	void update(Container* c, Uint32 time);

private:
	GameObject* fighter_;
	const vector<Asteroid*>* asteroids_;
};

