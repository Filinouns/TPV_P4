#pragma once
#include "InputComponent.h"
class RotationIC : public InputComponent
{
public:
	RotationIC(SDL_Keycode ctrlKey0, SDL_Keycode ctrlKey1, float angle);
	virtual ~RotationIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
private:
	SDL_Keycode ctrlKey0_;
	SDL_Keycode ctrlKey1_;
	float ang_;
};

