#pragma once
#include <string>
#include "Worker.h"
#include <iostream>
#include <fstream>

using namespace std;

class Logger {
public:
	inline static void initInstance(string filename);
	inline static Logger* instance();
	void log(string info);
	void log(function<string()> f);

	Logger();
	virtual ~Logger();

private:
	Worker worker_;
	ofstream log_;
	static shared_ptr<Logger> instance_;
};

