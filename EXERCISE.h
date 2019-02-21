#pragma once

//This is for part 1
class ILogger {
public:
    virtual ILogger& LogInfo(const std::string& msg)=0;
    virtual ILogger& LogError(const std::string& msg) = 0;
    virtual const std::string& GetLastError() = 0;
    virtual ~ILogger() = default;
};

// This is for Part 2/3
class StringLogger : public ILogger {
private:
    std::ostream& stream;
    std::string lastError{};

public:
    StringLogger(std::ostream& strm) : stream{strm}{}
    ILogger& LogInfo(const std::string& msg) override {
        stream << "INFO: " << msg;
        return *this;
    }

    ILogger& LogError(const std::string& msg) override {
        stream << "ERROR: " << msg;
        lastError = msg; //copy the passed string into lastError
    }

    const std::string& GetLastError() override {
        return lastError;
    }
};

