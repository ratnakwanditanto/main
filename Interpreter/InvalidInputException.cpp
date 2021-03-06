//@author A0086626W
#include "InvalidInputException.h"
#include "MCLogger.h"

InvalidInputException::InvalidInputException(std::string msg) {
	MCLogger::log("EXCEPTION: " + msg);
    _message = msg;
}

InvalidInputException::~InvalidInputException(void) {
}

const char* InvalidInputException::what() const throw() {
     return _message.c_str();
}