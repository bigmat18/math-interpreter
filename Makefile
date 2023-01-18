SRC_DIR = src
BUILD_DIR = build/debug
CC = gcc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = lenguage
COMPILER_FLAGS = -std=c11 -Wall -O0 -g -pedantic

main:
	$(CC) $(COMPILER_FLAGS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)