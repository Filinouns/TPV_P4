#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "FighterMove.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include "ReduceSpeedPC.h"
#include "GunIC.h"

class Fighter :	public Container {
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();

	void initFighter();

	bool getRotating() { return rotating_; }
	void setRotating(bool r) { rotating_ = r; }
	void setRot(int r) { rot_ = r; }
	int getRot() { return rot_; }

	bool getMoving() { return moving_; }
	void setMoving(bool b) { moving_ = b; }

	void receive(const void* senderObj, const msg::Message& msg);

private:

	//Components
	ImageGC fighterImage_;
	FighterMove fighterMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;

	bool moving_ = false;
	bool rotating_ = false;
	int rot_ = 0;
};

