#include "config.h"

#include <err.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>

namespace btc {

void Config::Parse() {
    FILE*   config_file;

    if ((config_file = fopen(file_name_.c_str(), "r")) == NULL) {
        err(1, "Can't open config file %s", file_name_.c_str());
    }

    char*       line = NULL;
    size_t      line_capacity = 0;
    ssize_t     line_length;
    std::string config_data;
    while ((line_length = getline(&line, &line_capacity, config_file)) > 0) {
        config_data.append(line, line_length);
    }

    fclose(config_file);

    ParseFromString(config_data);
}

}   // namespace btc
