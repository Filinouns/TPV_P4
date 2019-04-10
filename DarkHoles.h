#pragma once
#include "GameObjectPool.h"
#include "VeryDarkHole.h"

#include "ImageGC.h"
#include "RotatingPC.h"

class DarkHoles : public GameObjectPool<VeryDarkHole, 50> {
public:
	DarkHoles(SDLGame* game);
	virtual ~DarkHoles();

	void InitHoles();
	void DuplicateHoles();
	void callLogger(Vector2D p);

	void receive(const void* senderObj, const msg::Message& m);

private:
	Vector2D randPos();

	int numHoles_;
	int initHoles_ = 2;

	// component for Asteroid
	ImageGC blackHoleImage_;
	RotatingPC rotating_;
};