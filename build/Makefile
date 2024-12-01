CC = g++
CFLAGS = -Wall -g
SRC_DIR = ..
BIN_DIR = ../bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TARGETS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%)

all: $(TARGETS)

$(BIN_DIR)/%: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
