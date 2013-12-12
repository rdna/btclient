#include "btclient.h"

#include <unistd.h>

int main(int argc, char** argv) {
    btc::Options options(argc, argv);
    options.Parse();

    btc::Config config(options.config_file());
    config.Parse();

    btc::Api::Init();

    btc::Api public_api(config.public_api_url());
    btc::Api trade_api(config.trade_api_url(), config.key(), config.secret());

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
