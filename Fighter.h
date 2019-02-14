#pragma once

#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include "ReduceSpeedPC.h"
/*
#include "GunIC.h"
*/

class Fighter :	public Container {
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();

private:


	//Components
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	/*
	GunIC normalGun_;
	*/
};

