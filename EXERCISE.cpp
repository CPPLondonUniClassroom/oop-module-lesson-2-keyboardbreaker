#include "EXERCISE.h"

// This is for Part 2/3

int StringLogger::num = 2; //one definition rule
StringLogger::StringLogger(std::ostream& strm) : stream{strm}{}

ILogger& StringLogger::LogInfo(const std::string& msg) {
    stream << "INFO: " << msg;
    return *this;
}

ILogger& StringLogger::LogError(const std::string& msg) {
    stream << "ERROR: " << msg;
    lastError = msg; //copy the passed string into lastError
    return *this;
}

const std::string& StringLogger::GetLastError() const {
    return lastError;
}

int StringLogger::Version() {
    return num;
}
