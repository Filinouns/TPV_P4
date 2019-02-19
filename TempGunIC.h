#pragma once

#include "InputComponent.h"

class TempGunIC : public InputComponent {
public:
	TempGunIC(SDL_Keycode ctrlKey);
	virtual ~TempGunIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
private:
	SDL_Keycode ctrlKey_;
};

