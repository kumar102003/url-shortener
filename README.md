# URL Shortener

A simple URL shortener service built with C++, Crow framework, and MySQL.

## Prerequisites

- C++17 compatible compiler
- CMake 3.10 or higher
- MySQL Server
- Git

## Setup

1. Clone the repository:
```bash
git clone <repository-url>
cd url-shortener
```

2. Set up the MySQL database:
```bash
mysql -u root -p < database.sql
```

3. Configure the database connection:
Edit `src/config.h` and update the MySQL credentials:
```cpp
#define MYSQL_HOST "localhost"
#define MYSQL_USER "your_username"
#define MYSQL_PASSWORD "your_password"
#define MYSQL_DATABASE "url_shortener"
```

4. Build the project:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage

1. Start the server:
```bash
./url_shortener
```

2. The server will start on `http://localhost:8080`

3. API Endpoints:

   - Shorten URL:
     ```bash
     curl -X POST http://localhost:8080/shorten \
          -H "Content-Type: application/json" \
          -d '{"url": "https://example.com"}'
     ```

   - Access shortened URL:
     ```
     http://localhost:8080/<short_code>
     ```

## Features

- Generates 6-character random short URLs
- Stores URLs in MySQL database
- RESTful API endpoints
- Automatic redirection from short to long URLs

## Error Handling

- Returns 400 for invalid requests
- Returns 404 for non-existent short URLs
- Proper error handling for database operations

## Security

- Input validation for URLs
- SQL injection prevention
- Basic error handling

## License

MIT License