CC := g++
CFLAGS := -Wall -std=c++11 -I/usr/include/SDL2
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
STABLE_DIR := stable

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
EXECUTABLE := $(BIN_DIR)/verlet.draw

P=assets/images/ww.png

.PHONY: all clean run

all: clean $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXECUTABLE): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) $(P)

ship: $(EXECUTABLE)
	@mkdir -p $(STABLE_DIR)
	cp $(EXECUTABLE) $(STABLE_DIR)/

stable: $(STABLE_EXE)
	./$(STABLE_EXE)

unplug:
	rm -f $(STABLE_DIR)/*

