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

all: intro $(BINARY)

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

dynamic:
	@leaks --atExit -- ./exe

$(BINARY): $(OBJECTS)
	@echo "Linking started..!!!"
	$(CC) $(LFLAGS) $(WARNS) $(INCLUDES) $^ -o $@
	@echo "Linking done!!!"
	@echo "Build finished!!!"

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@echo "Compilation started...!!!"
	$(CC) $(CFLAGS) $(WARNS) $(INCLUDES) $< -o $@
	@echo "Compilation done!!!"

.PHONY: all clean debug intro run