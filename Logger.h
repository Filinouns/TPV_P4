#pragma once
#include <string>
#include "Worker.h"
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

class Logger {
public:
	virtual ~Logger();

	inline static void initInstance(string filename) {
		if (instance_.get() == nullptr) {
			instance_.reset(new Logger(filename));
		}
	};
	inline static Logger* instance() {
		if (instance_.get() != nullptr)
			return instance_.get();
	};
	void log(string info);
	void log(function<string()> f);

	Logger(Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

private:
	Logger(string filename);
	string fn_;
	Worker worker_;
	ofstream log_;
	static unique_ptr<Logger> instance_;
};

