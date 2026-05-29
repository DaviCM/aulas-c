# Atribuição com := é feita apenas uma vez
CC := gcc
CFLAGS := -fdiagnostics-color=always -Wall -Wextra -std=c23 -pedantic -g

BIN := ./bin

SRC := $(wildcard dia*/*.c)
TARGETS := $(patsubst %.c, $(BIN)/%, $(SRC))

$(BIN)/%: %.c
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) $< -o $@
	clear


all: $(TARGETS)


run: $(BIN)/$(f)
	$(BIN)/$(f)


rm:
	@rm -f $(BIN)/$(f)


.PHONY: all run rm