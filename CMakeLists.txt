cmake_minimum_required(VERSION 3.10)
project(url_shortener)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find MySQL
find_package(MySQL REQUIRED)

# Add Crow as a subdirectory
add_subdirectory(Crow-master)

# Add source files
set(SOURCES
    src/main.cpp
    src/server.cpp
    src/database.cpp
    src/shortener.cpp
)

# Create executable
add_executable(url_shortener ${SOURCES})

# Include directories
target_include_directories(url_shortener PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${MYSQL_INCLUDE_DIR}
)

# Link libraries
target_link_libraries(url_shortener PRIVATE
    ${MYSQL_LIBRARIES}
    Crow::Crow
)
