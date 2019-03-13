#include "Asteroids.h"
#include "Messages_defs.h"
#include "ServiceLocator.h"

Asteroids::Asteroids(SDLGame* game) : GameObjectPool(game), rotating_(5),
asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
numAsteroids_(1)
{
	srand(time(0));
	initAst_ = numAsteroids_;

	for (auto o : getAllObjects()) {
		o->addC(&rotating_);
		o->addC(&naturalMove_);
		o->addC(&asteroidImage_);
		o->addC(&showUpAtOppositeSide_);
	}
}

Asteroids::~Asteroids() {}


void Asteroids::InitAsteroids() {
	//Crea tantos asteroides como se pidan
	int n = initAst_;

	for (int i = 0; i < n; i++) {
		if (getUnusedObject() != nullptr) {

			Asteroid *a = getUnusedObject();
			a->setActive(true);
			a->setPosition(randPos());

			Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
			Vector2D v = (c - a->getPosition()).normalize() * ((rand() % 10 + 1) / 20.0);
			a->setVelocity(v);

			a->setHeight(20);
			a->setWidth(20);

			a->setGenerations(3);
		}
	}
	
	setId(msg::Asteroids);

	setActive(false);
}

//Arreglar las posiciones
Vector2D Asteroids::randPos() {
	Vector2D p = Vector2D(0, 0);
	int aux = rand() % 4;

	switch (aux) {
		//Arriba
	case 0:
		p = Vector2D(rand() % this->getGame()->getWindowWidth(), rand() % 50);
		break;
		//Abajo
	case 1:
		p = Vector2D(rand() % this->getGame()->getWindowWidth(), rand() % 50 + (this->getGame()->getWindowHeight() - 50));
		break;
		//Izq
	case 2:
		p = Vector2D(rand() % 50, rand() % this->getGame()->getWindowHeight());
		break;
		//Der
	case 3:
		p = Vector2D(rand() % 50 + (this->getGame()->getWindowWidth() - 50), rand() % this->getGame()->getWindowHeight());
		break;
	default:
		break;
	}

	return p;
}

void Asteroids::GenerateSonAsteroid(Asteroid* father) {
	for (int i = 0; i < 2; i++) {
		if (getUnusedObject() != nullptr) {

			Asteroid *a = getUnusedObject();
			a->setActive(true);

			//Vel
			Vector2D v = father->getVelocity();
			v.setX(v.getX() * 1.1);
			v.setY(v.getY() * 1.1);

			a->setVelocity(v);

			//Pos
			a->setPosition(father->getPosition() + v + Vector2D(i * 10, 0));
			a->setRotation(i * 30);

			//Size
			a->setHeight(father->getHeight() * 0.75);
			a->setWidth(father->getWidth() * 0.75);

			//Generations
			a->setGenerations(father->getGenerations() - 1);
		}
	}
}

void Asteroids::receive(const void* senderObj, const msg::Message& m) {

	Container::receive(senderObj, m);

	switch (m.type_)	{

	case msg::GAME_START:
		this->getGame()->send(this, msg::AsteroidsInfo(getId(), msg::Broadcast, &getAllObjects()));
		break;

	case msg::ROUND_START:
		InitAsteroids();
		setActive(true);
		break;

	case msg::ROUND_OVER:
		this->deactiveAllObjects();
		setActive(false);
		break;

	case msg::BULLET_ASTEROID_COLLISION: {
		// Desactivamos el asteroide
		const msg::BulletAsteroidCollision m_ = static_cast<const msg::BulletAsteroidCollision&>(m);
		m_.asteroid_->setActive(false);
		numAsteroids_--;

		//sonido explosion por canal 2
		this->getGame()->getServiceLocator()->getAudios()->playChannel(Resources::Explosion, 0, 2);	

		
		// Mandar mensaje
		this->getGame()->send(this, msg::AsteroidDestroyed(getId(), msg::Broadcast, 4 - m_.asteroid_->getGenerations()));

		// Generar 2 hijos
		if (m_.asteroid_->getGenerations() > 1) { 
			GenerateSonAsteroid(m_.asteroid_); 
			numAsteroids_ += 2;
		}
		
		// Comprobamos el numero de asteroides
		if (numAsteroids_ == 0) {
 			this->getGame()->send(this, msg::Message(msg::NO_MORE_ASTEROIDS, getId(), msg::Broadcast));
			this->getGame()->getServiceLocator()->getAudios()->playMusic(Resources::Cheer, 3);	//sonido de victoria
		}

		//numero asteroides
		cout << numAsteroids_ << endl;
			break; 

	}
	default:
		break;
	}
}