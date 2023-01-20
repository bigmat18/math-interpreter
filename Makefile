SRC_DIR = src
CC = gcc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = lenguage
COMPILER_FLAGS = -std=c11 -Wall -O0 -g -pedantic

main:
	$(CC) $(COMPILER_FLAGS) $(SRC_FILES) -o $(OBJ_NAME)