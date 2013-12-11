#include "btclient.h"

#include <unistd.h>

static const char* kPublicUrl = "https://btc-e.com/api/2/";

static const char* kTradeUrl = "https://btc-e.com/tapi";
static const char* kKey = "Y0urKeY";
static const char* kSecret = "Y0urSecReT";

int main(int argc, char** argv) {
    btc::Api::Init();

    btc::Api public_api(kPublicUrl);
    btc::Api trade_api(kTradeUrl, kKey, kSecret);

    btc::ParamsVector trans_history_params;
    btc::Param<int> from("from", 0);
    btc::Param<int> count("count", 10);
    trans_history_params.push_back(&from);
    trans_history_params.push_back(&count);

    while (true) {
        public_api.SendRequest("btc_usd/ticker");
        public_api.HandleAnswer();

        trade_api.SendRequest("TransHistory", trans_history_params);
        trade_api.HandleAnswer();

        sleep(2);
    }

    btc::Api::Cleanup();

    return (0);
}
