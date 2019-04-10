#pragma once
#include "PhysicsComponent.h"
#include "VeryDarkHole.h"
class FighterHoleCollision : public PhysicsComponent
{
public:
	FighterHoleCollision();
	virtual ~FighterHoleCollision();

	void update(Container* c, Uint32 time);
	void receive(Container* c, const msg::Message& msg);
private:
	GameObject* fighter_;
	const vector<VeryDarkHole*>* holes_;
};

