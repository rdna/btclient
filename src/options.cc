#include "options.h"

#include <stdlib.h>
#include <cstdio>

namespace btc {

void Options::Usage() const {
    fprintf(stderr, "Usage: %s -c config_file\n", program_name_.c_str());
    exit(1);
}

void Options::Parse() {
    int     option;
    while ((option = getopt(argc_, argv_, "c:")) != -1) {
        switch (option) {
            case 'c':
                config_file_ = optarg;
                break;
            default:
                Usage();
        }
    }
    argc_ -= optind;
    argv_ += optind;

    Check();
}

void Options::Check() {
    if (config_file_.empty()) {
        fprintf(stderr, "%s: Config file is not set.\n", program_name_.c_str());
        Usage();
    }
}

}   // namespace btc
