#pragma once
#include <string>
#include <iostream>

//This is for part 1
class ILogger {
public:
    virtual ILogger& LogInfo(const std::string& msg)=0;
    virtual ILogger& LogError(const std::string& msg) = 0;
    virtual const std::string& GetLastError() const = 0;
    virtual ~ILogger() = default;
};

class StringLogger : public ILogger {
private:
    std::ostream& stream;
    std::string lastError{};
    static int num;

public:
    StringLogger(std::ostream& strm);
    ILogger& LogInfo(const std::string& msg) override;

    ILogger& LogError(const std::string& msg) override;

    const std::string& GetLastError()const override;

    static int Version();
};


