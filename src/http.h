#pragma once

#include <string>

#include <curl/curl.h>

namespace http {

class Library {
public:
    static void Init();
    static void Cleanup();
};

class Client {
public:
    Client();
    ~Client();

    inline std::string answer() const {
        return answer_;
    }

    void AddHeader(const std::string header);
    void SetHeaders();
    void SetPostFields(const std::string data);
    void Send(const std::string url);

private:
    static size_t SaveAnswer(char *data, size_t size, size_t count,
                               void *instance);

    CURL* handle_;
    struct curl_slist* headers_;
    std::string answer_;
};

}   // namespace http
