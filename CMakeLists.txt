cmake_minimum_required(VERSION 3.10)
project(URL_Shortener)

set(CMAKE_CXX_STANDARD 17)

# MySQL Server paths
include_directories("C:/Program Files/MySQL/MySQL Server 8.0/include/")
link_directories("C:/Program Files/MySQL/MySQL Server 8.0/lib/")

# Add executable
add_executable(url_shortener main.cpp server.cpp database.cpp shortener.cpp)

# Link MySQL C API library
target_link_libraries(url_shortener libmysql)
