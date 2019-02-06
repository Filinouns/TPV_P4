#pragma once

#include "GameObject.h"

template <typename T, int SIZE>
class ObjectPool : public GameObject {
public:
	ObjectPool(SDLGame* game);
	virtual ~ObjectPool();

	virtual void handleInput(Uint32 time, const SDL_Event& event);
	virtual void update(Uint32 time);
	virtual void render(Uint32 time);

	//virtual void addObj() = 0;

protected:
	T* getUnusedObj();

private:
	static int const MAX_OBJ = SIZE;
	T objs_[MAX_OBJ];
};

template <typename T, int SIZE>
ObjectPool<T, SIZE>::ObjectPool(SDLGame* game) : GameObject(game) {
	for (int i = 0; i < MAX_OBJ; i++) {
		objs_[i].setActive(false);
		objs_[i].setGame(game);
	}
}

template <typename T, int SIZE>
ObjectPool<T, SIZE>::~ObjectPool() {}

template <typename T, int SIZE>
void ObjectPool<T, SIZE>::handleInput(Uint32 time, const SDL_Event& event) {
	for (int i = 0; i < MAX_OBJ; i++)
		if (objs_[i].isActive()) {
			objs_[i].handleInput(time, event);
		}
}

template <typename T, int SIZE>
void ObjectPool<T, SIZE>::update(Uint32 time) {
	for (int i = 0; i < MAX_OBJ; i++)
		if (objs_[i].isActive()) {
			objs_[i].update(time);
		}
}

template <typename T, int SIZE>
void ObjectPool<T, SIZE>::render(Uint32 time) {
	for (int i = 0; i < MAX_OBJ; i++)
		if (objs_[i].isActive()) {
			objs_[i].render(time);
		}
}

template <typename T, int SIZE>
T* ObjectPool<T, SIZE>::getUnusedObj() {
	for (int i = 0; i < MAX_OBJ; i++)
		if (!objs_[i].isActive()) {
			return &objs_[i];
		}
	return nullptr;
}