CC = g++
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17
LDFLAGS = -lSDL2

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = build
ASSETS_DIR = assets

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

EXEC = ColeusMaze

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXEC) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)  # This will ensure the 'build' directory exists
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: clean
