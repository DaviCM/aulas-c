# Atribuição com := é feita apenas uma vez
CC := gcc
CFLAGS := -fdiagnostics-color=always -Wall -Wextra -std=c23 -pedantic -g

BIN := ./bin

SRC := $(wildcard dia*/*.c)
TARGETS := $(patsubst %.c, $(BIN)/%, $(SRC))

FILE := $(BIN)/$(word 2,$(MAKECMDGOALS))

all: $(TARGETS)


$(BIN)/%: %.c
	@mkdir -p $(dir $@) 
	$(CC) $(CFLAGS) $< -o $@


# Irá chamar o comando de compilação utilizado anteriormente, mas de forma mais clara!
build:
	@$(MAKE) $(FILE)


run:
	@$(FILE)


rm:
	@rm -f $(FILE)


# hack legalizado do Make: um target que aceita qualquer match e sai silenciosamente para evitar erros no run.
%:
	@:


.PHONY: all run rm


# MAKECMDGOALS pega todos os parâmetros passados ao Make na execução
# o primeiro será "run" e o segundo o path ao arquivo, então pegamos apenas esse com "word 2"
# que retira a segunda palavra, separada por espaço. Nesse caso, da função.