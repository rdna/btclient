#pragma once

#include <string>

#include <json/json.h>

namespace json {

class Answer {
public:
    Answer() { }

    void Parse(const std::string data);

    inline const Json::Value& root() const {
        return root_;
    }

private:
    Json::Value root_;
    Json::Reader reader_;
};

}   // namespace json
