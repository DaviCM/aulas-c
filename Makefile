CC := gcc
CFLAGS := -fdiagnostics-color=always -Wall -Wextra -std=c23 -pedantic -g

# Declaramos um wildcard, um "fetch" para o make pegar os arquivos
# de pastas que começam com 'dia'.
SRC := $(wildcard dia*/*.c)

# Substitui corretamente os arquivos com patsubst do caminho encontrado pela pasta bin
BIN := $(patsubst %.c,bin/%,$(SRC))

# Shortcut do make que aplica o comando de compilação em cada arquivo $< (primeira dependência)
all: $(BIN)

# Compilação normal
bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@