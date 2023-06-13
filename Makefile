# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
#CXXFLAGS = -std=c++11 -O3 -Wall

# Folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# All sources, objects, and header files
MAIN = Main
TARGET = run.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

$(BIN_FOLDER)$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) $(OBJ)

all: $(BIN_FOLDER)$(TARGET)

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*

run: $(BIN_FOLDER)$(TARGET)
	./$(BIN_FOLDER)$(TARGET) $(ARGS)

ARGS := $(filter-out $@,$(MAKECMDGOALS))
ifeq ($(ARGS),)
    ARGS := default_argument
endif
