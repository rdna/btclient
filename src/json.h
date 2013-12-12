#pragma once

#include <string>

#include <json/json.h>

namespace json {

class Data {
public:
    Data() { }
    virtual ~Data() { }

    virtual void ParseFromString(const std::string data);

    inline const Json::Value& root() const {
        return root_;
    }

private:
    Json::Value root_;
    Json::Reader reader_;
};

class Config : public Data {
public:
    Config() { }

    inline std::string GetKeyAsString(const std::string key) const {
        return root()[key].asString();
    }

    inline std::string key() const {
        return GetKeyAsString("key");
    }

    inline std::string secret() const {
        return GetKeyAsString("secret");
    }

    inline std::string public_api_url() const {
        return GetKeyAsString("public_api_url");
    }

    inline std::string trade_api_url() const {
        return GetKeyAsString("trade_api_url");
    }
};

}   // namespace json
