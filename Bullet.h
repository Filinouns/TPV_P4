#pragma once

#include "Container.h"

class Bullet : public Container {
public:
	Bullet();
	Bullet(SDLGame* game);
	virtual ~Bullet();

	int getPower() { return power_; }
	void setPower(int p) { power_ = p; }

private:
	int power_;
};

