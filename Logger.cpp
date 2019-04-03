#include "Logger.h"

Logger::Logger() {
	worker_.start();
	log_.open("/tmp/file.txt", ios::in||ios::binary && ios::app);
}

Logger::~Logger() {
	log_.close();
	worker_.stop();
}

void Logger::log(string info) {
	worker_.execute([this, info]() { log_ << info << endl; });
}

void Logger::log(function<string()> f){
	worker_.execute([this, f]() { log_ << f() << endl; });
}

void Logger::initInstance(string filename) {
	if (instance_.get() == nullptr) instance_.reset(new Logger());
}

inline Logger * Logger::instance() {
	if (instance_.get() == nullptr)
		instance_.reset(new Logger());
	return instance_.get();
}

