#include "crow_all.h"
#include "shortener.h"
#include "database.h"
#include <iostream>

void startServer() {
    crow::SimpleApp app;
    initDatabase();  // Initialize MySQL Database

    // Shorten URL
    CROW_ROUTE(app, "/shorten").methods("POST"_method)([](const crow::request& req){
        auto json = crow::json::load(req.body);
        if (!json || !json["url"].s()) {
            return crow::response(400, "Invalid URL");
        }

        std::string longUrl = json["url"].s();
        std::string shortUrl = shortenURL(longUrl);
        saveURL(shortUrl, longUrl);

        crow::json::wvalue res;
        res["short_url"] = "http://localhost:8080/" + shortUrl;
        return crow::response(res);
    });

    // Redirect from short URL to original URL
    CROW_ROUTE(app, "/<string>").methods("GET"_method)([](std::string shortCode) {
        std::string longUrl = getOriginalURL(shortCode);
        if (longUrl.empty()) {
            return crow::response(404, "URL not found");
        }
        crow::response res(302);
        res.add_header("Location", longUrl);
        return res;
    });

    app.port(8080).multithreaded().run();
}
