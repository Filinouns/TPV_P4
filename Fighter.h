#ifndef _AA
#define _AA

#include "BulletInt.h"
#include "GameObject.h"

/*
 *
 */
class Fighter : public GameObject {
public:
	Fighter(SDLGame* game, BulletInt* bi);
	virtual ~Fighter();
	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);
private:
	Texture* fighterTexture_;
	SDL_Rect clip_;
	BulletInt* bi_;
};

#endif _AA
