#include "database.h"
#include "config.h"
#include <mysql/mysql.h>
#include <iostream>

MYSQL *conn;

void initDatabase() {
    conn = mysql_init(nullptr);
    if (!conn) {
        std::cerr << "MySQL initialization failed!" << std::endl;
        exit(1);
    }

    if (!mysql_real_connect(conn, MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE, 0, NULL, 0)) {
        std::cerr << "MySQL connection failed: " << mysql_error(conn) << std::endl;
        exit(1);
    }

    std::string createTableSQL =
        "CREATE TABLE IF NOT EXISTS urls ("
        "short_url VARCHAR(10) PRIMARY KEY, "
        "long_url TEXT NOT NULL"
        ");";
    
    if (mysql_query(conn, createTableSQL.c_str())) {
        std::cerr << "Error creating table: " << mysql_error(conn) << std::endl;
    }
}

void saveURL(const std::string& shortUrl, const std::string& longUrl) {
    std::string sql = "INSERT INTO urls (short_url, long_url) VALUES ('" + shortUrl + "', '" + longUrl + "');";
    if (mysql_query(conn, sql.c_str())) {
        std::cerr << "Error saving URL: " << mysql_error(conn) << std::endl;
    }
}

std::string getOriginalURL(const std::string& shortUrl) {
    std::string sql = "SELECT long_url FROM urls WHERE short_url = '" + shortUrl + "';";
    if (mysql_query(conn, sql.c_str())) {
        std::cerr << "Error fetching URL: " << mysql_error(conn) << std::endl;
        return "";
    }

    MYSQL_RES* res = mysql_store_result(conn);
    if (!res) {
        return "";
    }

    MYSQL_ROW row = mysql_fetch_row(res);
    std::string longUrl = (row) ? row[0] : "";
    
    mysql_free_result(res);
    return longUrl;
}
