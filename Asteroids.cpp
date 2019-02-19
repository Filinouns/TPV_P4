#include "Asteroids.h"

Asteroids::Asteroids(SDLGame* game) : GameObjectPool(game), rotating_(5),
asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
numAsteroids_(10)
{
	//Crea tantos asteroides como se pidan
	for (int i = 0; i < numAsteroids_; i++) {
		Asteroid *a = getUnusedObject();
		a->setActive(true);
	}

	//Les da los componentes y atributos que necesitan a los asteroid
	for (auto o : getAllObjects()) {
		//o = getUnusedObject();
		o->addC(&rotating_);
		o->addC(&naturalMove_);
		o->addC(&asteroidImage_);
		o->addC(&showUpAtOppositeSide_);

		o->setPosition(Vector2D(rand() % game->getWindowHeight(), rand() % game->getWindowWidth()));
		o->setVelocity(Vector2D(rand() % 3, rand() % 3));
	}
}

Asteroids::~Asteroids() {}