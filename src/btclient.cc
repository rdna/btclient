#include "btclient.h"

#include <iostream>
#include <string>

namespace btc {

void Api::SendRequest(const std::string type) {
    http_client_.Send(url_ + type);
}

void Api::SendRequest(const std::string method, const ParamsVector& params) {
    std::string post_fields = "nonce=" + GetNonce() + "&method=" + method;
    for (ParamsVector::const_iterator param_it = params.begin();
            param_it != params.end(); ++param_it) {
        post_fields.append("&" + (*param_it)->Get());
    }
    std::string signed_post_fields = hmac_.Compute(secret_, post_fields);

    http_client_.AddHeader("Key: " + key_);
    http_client_.AddHeader("Sign: " + signed_post_fields);
    http_client_.AddHeader("Content-type: application/x-www-form-urlencoded");
    http_client_.SetHeaders();
    http_client_.SetPostFields(post_fields);

    http_client_.Send(url_);
}

void Api::HandleAnswer() {
    answer_.Parse(http_client_.answer());
    std::cout << answer_.root();
}

}   // namespace btc
