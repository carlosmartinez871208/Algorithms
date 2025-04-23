# Generic make file
SRC_DIR := .
OBJ_DIR  = .

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

BINARY = exe

INCLUDES =\

# Flags:
CC = g++-14
# Use gdb in case of using linux
#DBG = GDB
DBG = lldb
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function
CFLAGS = -std=c++20 -g -c
LFLAGS = -std=c++20

all: clean intro build run

build: $(OBJECTS) $(BINARY)

clean:
	@echo "Cleanning project...!!!"
	@rm -rf exe *.o
	@echo "Cleanning done!!!"

debug:
	@echo "Debugging project...!!"
	@$(DBG) $(BINARY)

intro:
	@echo "Building project...!!!"

run:
	@echo "Running...!!!"
	@./$(BINARY)

$(BINARY):
	@echo "Linking started..!!!"
	$(CC) $(WARNS) $(LFLAGS) $(INCLUDES) $(OBJ_DIR)/*.o -o $@
	@echo "Linking done!!!"
	@echo "Build finished!!!"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@echo "Compilation started...!!!"
	$(CC) $(WARNS) $(CFLAGS) $(INCLUDES) $< -o $@
	@echo "Compilation done!!!"

.PHONY: all build clean debug intro post_build run