CC := gcc
CFLAGS := -fdiagnostics-color=always -Wall -Wextra -std=c23 -pedantic -g

# Declaramos um wildcard, um "fetch" para o make pegar os arquivos
# de pastas que começam com 'dia'.
SRC := $(wildcard dia*/*.c)

# Substitui corretamente os arquivos do caminho encontrado pela pasta bin, que é * dia*/{arquivo}.c
BIN := $(patsubst %.c,bin/%,$(SRC))

# Shortcut do make que aplica o comando de compilação em cada arquivo $< (primeira dependência)
all: $(BIN)

# Compilação normal, criando o diretório se não existir, rodando GCC e executando o arquivo.
bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@
	$@


# Make resolve automaticamente $< e $@, que são respectivamente o primeiro prerequisito para o comando
# e o produto dele, ou o alvo.