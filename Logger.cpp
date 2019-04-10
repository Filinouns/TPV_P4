#include "Logger.h"

unique_ptr<Logger> Logger::instance_;

Logger::Logger(string filename) : fn_(filename) {
	worker_.start();
	log_.open(filename);
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