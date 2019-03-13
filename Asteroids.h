#pragma once

#include "GameObjectPool.h"
#include "Asteroid.h"

#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotatingPC.h"

class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();

	void InitAsteroids();
	void GenerateSonAsteroid(Asteroid* father);


	void receive(const void* senderObj, const msg::Message& msg);

private:
	Vector2D randPos();

	//Asteroid a_;
	int initAst_;
	int numAsteroids_ = 0;

	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};