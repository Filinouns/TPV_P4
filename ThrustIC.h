#pragma once

#include "InputComponent.h"

class ThrustIC : public InputComponent {
public:
	ThrustIC(SDL_Keycode ctrlKey, float thrust, float speedLimit);
	virtual ~ThrustIC();
	virtual void handleInput(Container* c, Uint32 time, const SDL_Event& event);
private:
	SDL_Keycode ctrlKey_;
	float thrust_;
	float speedLimit_;
};

