# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17

# Directories
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

# Source files and target executable
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/ColeusMaze

# Include directory
INCLUDES = -I$(INC_DIR)

# Build target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean target
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
