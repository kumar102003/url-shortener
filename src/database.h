#ifndef DATABASE_H
#define DATABASE_H

#include <string>

void initDatabase();
void saveURL(const std::string& shortUrl, const std::string& longUrl);
std::string getOriginalURL(const std::string& shortUrl);

#endif // DATABASE_H
