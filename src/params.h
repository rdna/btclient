#pragma once

#include <sstream>
#include <string>

namespace btc {

class ParamInterfase {
public:
    virtual std::string name() const = 0;
    virtual std::string Get() const = 0;
};

template <typename Type>
class Param : public ParamInterfase {
public:
    Param(const std::string name, const Type value)
        : name_(name)
        , value_(value)
    { }

    virtual std::string name() const {
        return name_;
    }

    virtual Type value() const {
        return value_;
    }

    virtual std::string Get() const {
        std::stringstream string_stream;
        string_stream << name_ << "=" << value_;
        return string_stream.str();
    }

private:
    std::string name_;
    Type value_;
};

}   // namespace btc
