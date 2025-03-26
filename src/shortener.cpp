#include "shortener.h"
#include <random>
#include <algorithm>

std::string shortenURL(const std::string& longUrl) {
    const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int length = 6;  // Length of the short URL

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.size() - 1);

    std::string shortUrl;
    shortUrl.reserve(length);

    for (int i = 0; i < length; ++i) {
        shortUrl += chars[dis(gen)];
    }

    return shortUrl;
}
