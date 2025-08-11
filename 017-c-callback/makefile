# Generic make file

SRC_DIR := .
OBJ_DIR  = .

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

BINARY = exe

INCLUDES =\

# Flags:
CC = gcc-14
# Use gdb in case of using linux
#DBG = GDB
DBG = lldb
WARNS = -Wall -Werror -Wpedantic -Wno-unused-variable -Wno-unused-function -Werror-implicit-function-declaration
CFLAGS = -c -std=gnu11 -g
LFLAGS = -std=gnu11

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

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "Compilation started...!!!"
	$(CC) $(WARNS) $(CFLAGS) $(INCLUDES) $< -o $@
	@echo "Compilation done!!!"

.PHONY: all build clean debug intro post_build run