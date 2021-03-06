#pragma once
#include "PhysicsComponent.h"

#include "Bullet.h"
#include "Asteroid.h"

class BulletsAsteroidsCollision : public PhysicsComponent {
public:
	BulletsAsteroidsCollision();
	virtual ~BulletsAsteroidsCollision();
	void update(Container* c, Uint32 time);

	virtual void receive(Container* c, const msg::Message& msg);

private:
	const vector<Asteroid*>* asteroids_;
	const vector<Bullet*>* bullets_;
};