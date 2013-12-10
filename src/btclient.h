#pragma once

#include "crypto.h"
#include "http.h"
#include "json.h"

#include <ctime>
#include <string>
#include <sstream>

namespace btc {

class Api {
public:
    struct MethodParams {
        // TODO(rdna@): Support params for all the methods.
    };

    explicit Api(const std::string url)
        : url_(url)
    { }

    Api(const std::string url,
             const std::string key,
             const std::string secret)
        : url_(url)
        , key_(key)
        , secret_(secret)
    { }

    static void Init() {
        http::Library::Init();
    }

    static void Cleanup() {
        http::Library::Cleanup();
    }

    void SendRequest(const std::string type);
    void SendRequest(const std::string method, const MethodParams params);
    void HandleAnswer();

private:
    inline std::string GetNonce() const {
        std::stringstream string_stream;
        string_stream << time(NULL);
        return string_stream.str();
    }

    http::Client http_client_;
    std::string url_;

    std::string key_;
    std::string secret_;
    std::string method_;
    crypto::Hmac hmac_;

    json::Answer answer_;
};

}   // namespace btc
