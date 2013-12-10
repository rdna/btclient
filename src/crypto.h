#pragma once

#include <string>

#include <openssl/hmac.h>

namespace crypto {

class Hmac {
public:
    Hmac();
    ~Hmac();

    std::string Compute(const std::string key, const std::string message);

private:
    HMAC_CTX hmac_ctx_;
};

}   // namespace crypto
