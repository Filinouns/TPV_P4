#pragma once
#include "PhysicsComponent.h"
#include "VeryDarkHole.h"
#include "Bullet.h"
class BulletsHoleCollision : public PhysicsComponent
{
public:
	BulletsHoleCollision();
	virtual ~BulletsHoleCollision();

	void update(Container* c, Uint32 time);

	virtual void receive(Container* c, const msg::Message& msg);

private:
	const vector<Bullet*>* bullets_;
	const vector<VeryDarkHole*>* holes_;
};

