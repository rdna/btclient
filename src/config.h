#pragma once

#include "json.h"

#include <string>

namespace btc {

class Config : public json::Config {
public:
    Config(const std::string file_name)
        : file_name_(file_name)
    { }

    void Parse();

private:
    std::string file_name_;
};

}   // namespace btc
