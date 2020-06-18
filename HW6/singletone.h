#pragma once
#include <string>

class LoggerSingleton {
public:
    static LoggerSingleton* Log() {
        {if (!loggerInstance_) {
            loggerInstance_ = new LoggerSingleton{};
        } return loggerInstance_;
        }
    }
    ;
    void Debug(std::string);
    void Trace(std::string);
    void Warning(std::string);
    void Info(std::string);
    void Error(std::string);
    LoggerSingleton(const LoggerSingleton& rhs) = delete;

private:
    LoggerSingleton() = default;
    static inline LoggerSingleton* loggerInstance_{ nullptr };
}
;