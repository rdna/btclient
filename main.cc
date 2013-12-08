#include "btclient.h"

#include <unistd.h>

static const char* kPublicUrl = "https://btc-e.com/api/2/";

static const char* kTradeUrl = "https://btc-e.com/tapi";
const static char* kKey = "Y0urKeY";
const static char* kSecret = "Y0urSecReT";

int main(int argc, char** argv) {
    btc::Api::Init();

    btc::Api public_api(kPublicUrl);
    btc::Api trade_api(kTradeUrl, kKey, kSecret);

    while (true) {
        public_api.SendRequest("btc_usd/ticker");
        public_api.HandleAnswer();

        trade_api.SendRequest("getInfo", btc::Api::MethodParams());
        trade_api.HandleAnswer();

        sleep(2);
    }

    btc::Api::Cleanup();

    return (0);
}
