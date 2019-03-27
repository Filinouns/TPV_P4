#pragma once
#include <SDL.h>
#include <functional>
#include "BlockingQueue.h"

using namespace std;
class Worker
{
public:
	Worker();
	virtual ~Worker();
	void start();
	void stop();
	void execute(function<void()> f);

private:
	static int start(void* o);
	void process();

	BlockingQueue<function<void()>> tasks_;
	SDL_Thread *t_;
	bool running;


};

