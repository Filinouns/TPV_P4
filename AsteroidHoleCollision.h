#pragma once
#include "PhysicsComponent.h"
#include "Asteroid.h"
#include "VeryDarkHole.h"

class AsteroidHoleCollision : public PhysicsComponent
{
public:
	AsteroidHoleCollision();
	virtual ~AsteroidHoleCollision();
	void update(Container* c, Uint32 time);

	virtual void receive(Container* c, const msg::Message& msg);

private:
	const vector<Asteroid*>* asteroids_;
	const vector<VeryDarkHole*>* holes_;
};

