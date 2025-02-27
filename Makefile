# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -I"C:/Program Files/MySQL/MySQL Server 8.0/include/"

# Linker flags (for MySQL)
LDFLAGS = -L"C:/Program Files/MySQL/MySQL Server 8.0/lib/" -lmysql

# Source files
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Output executable
TARGET = url-shortener

# Default build
all: $(TARGET)

# Compile the program
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile each .cpp file into .o (object file)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(OBJECTS) $(TARGET)
