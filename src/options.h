#pragma once

#include <string>

namespace btc {

class Options {
public:
    Options(int argc, char** argv)
        : argc_(argc)
        , argv_(argv)
        , program_name_(argv[0])
    { }

    inline std::string config_file() const {
        return config_file_;
    }

    void Usage() const;
    void Parse();

private:
    void Check();

    int argc_;
    char** argv_;
    std::string program_name_;
    std::string config_file_;
};

}   // namespace btc
