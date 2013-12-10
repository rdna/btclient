#include "crypto.h"

#include <err.h>
#include <cstdio>

#define CONVERT_BUFFER_LEN   3

namespace crypto {

Hmac::Hmac() {
    HMAC_CTX_init(&hmac_ctx_);
}

Hmac::~Hmac() {
    HMAC_CTX_cleanup(&hmac_ctx_);
}

std::string Hmac::Compute(const std::string key, const std::string message) {
    unsigned char message_digest[EVP_MAX_MD_SIZE];
    unsigned int  message_digest_len;
    if (!HMAC(EVP_sha512(),
              static_cast<const void *>(key.c_str()),
              key.size(),
              reinterpret_cast<const unsigned char *>(message.c_str()),
              message.size(),
              message_digest,
              &message_digest_len)) {
        err(1, "hmac: Can't compute authentication code.");
    }
    std::string result;
    char convert_buffer[CONVERT_BUFFER_LEN];
    for (int i = 0; i < message_digest_len; ++i) {
        snprintf(convert_buffer, CONVERT_BUFFER_LEN, "%02hhx",
                 *(message_digest + i));
        result.append(convert_buffer);
    }
    return result;
}

}   // namespace crypto
