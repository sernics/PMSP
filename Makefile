# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
# Source directory
SRC_DIR := src
# Object directory
OBJ_DIR := obj
# Binary directory
BIN_DIR := bin
# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
# Binary executable
TARGET := $(BIN_DIR)/main

# Build rule for the target
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

