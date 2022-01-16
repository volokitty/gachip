CC=gcc
BINARY_NAME=gachip
BUILD_DIR=build
SOURCE_DIR=src
EXAMPLES_DIR=examples

all:
	mkdir -p $(BUILD_DIR)
	$(CC) -Wall $(SOURCE_DIR)/*.c -o $(BUILD_DIR)/$(BINARY_NAME)

run:
	$(BUILD_DIR)/$(BINARY_NAME)

test:
	$(BUILD_DIR)/$(BINARY_NAME) $(EXAMPLES_DIR)/expr.g
