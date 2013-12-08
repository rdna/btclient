#include "http.h"

#include <err.h>
#include <cstdio>

namespace http {

static bool g_is_initialized = false;
static bool g_is_cleaned_up  = false;

void Library::Init() {
    if (g_is_initialized) {
        return;
    }
    if (curl_global_init(CURL_GLOBAL_SSL) != 0) {
        err(1, "libcurl: Can't initialize.");
    }
    g_is_initialized = true;
}

void Library::Cleanup() {
    if (g_is_cleaned_up) {
        return;
    }
    curl_global_cleanup();
    g_is_cleaned_up = true;
}

//----------------------------------------------------------------------

Client::Client()
        : headers_(NULL) {
    handle_ = curl_easy_init();
    if (curl_easy_setopt(handle_, CURLOPT_VERBOSE, 0) != CURLE_OK) {
        err(1, "libcurl: Can't set verbose mode.");
    }
    if (curl_easy_setopt(handle_, CURLOPT_WRITEFUNCTION, SaveAnswer) !=
            CURLE_OK) {
        err(1, "libcurl: Can't set write function.");
    }
    if (curl_easy_setopt(handle_, CURLOPT_WRITEDATA, this) != CURLE_OK) {
        err(1, "libcurl: Can't set write data.");
    }
}

Client::~Client() {
    if (headers_) {
        curl_slist_free_all(headers_);
    }
}

size_t Client::SaveAnswer(char* data, size_t size, size_t count,
                          void* instance) {
    std::string chunk(data, count * size);
    static_cast<Client *>(instance)->answer_.append(chunk);
    return chunk.size();
}

void Client::AddHeader(const std::string header) {
    headers_ = curl_slist_append(headers_, header.c_str());
}

void Client::SetHeaders() {
    if (curl_easy_setopt(handle_, CURLOPT_HTTPHEADER, headers_) != CURLE_OK) {
        err(1, "libcurl: Can't set headers.");
    }
}

void Client::SetPostFields(const std::string data) {
    if (curl_easy_setopt(handle_, CURLOPT_POSTFIELDS, data.c_str()) !=
            CURLE_OK) {
        err(1, "libcurl: Can't set POST fields.");
    }
    if (curl_easy_setopt(handle_, CURLOPT_POSTFIELDSIZE, data.size()) !=
            CURLE_OK) {
        err(1, "libcurl: Can't set POST fields size.");
    }
}

void Client::Send(const std::string url) {
    if (curl_easy_setopt(handle_, CURLOPT_URL, url.c_str()) != CURLE_OK) {
        err(1, "libcurl: Can't set URL.");
    }
    if (curl_easy_perform(handle_) != CURLE_OK) {
        err(1, "libcurl: Can't perform HTTP request.");
    }
}

}   // namespace http
