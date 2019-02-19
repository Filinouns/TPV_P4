#include "Bullet.h"

Bullet::Bullet() {
	width_ = 10;
	height_ = 10;

	//setId();
}

Bullet::Bullet(SDLGame * game) : Container(game) {
	Bullet();

}


Bullet::~Bullet()
{
}
