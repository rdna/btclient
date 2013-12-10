#include "json.h"

#include <err.h>

namespace json {

void Answer::Parse(const std::string data) {
    if (!reader_.parse(data, root_)) {
        err(1, "libjson: Can't parse data.");
    }
}

}   // namespace json
