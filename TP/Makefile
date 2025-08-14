# --- Configuración ---
CC      := gcc
CFLAGS  := -Wall -Wextra -std=c11
SRC_DIR := src
BIN_DIR := bin
CAPS    := 1 2 3 4 5

# Todos los .c de todos los capítulos
SRCS := $(foreach c,$(CAPS),$(wildcard $(SRC_DIR)/cap$(c)/*.c))
BINS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SRCS))

.PHONY: help all clean $(foreach c,$(CAPS),cap$(c)) clean-%

help:
	@echo "Uso:"
	@echo "  make all            -> compila todo"
	@echo "  make clean          -> borra todo lo compilado (bin/)"
	@echo "  make cap1           -> compila solo capítulo 1"
	@echo "  make clean-cap1     -> limpia solo capítulo 1"
	@echo "  (Luego añadimos: compilar un listing puntual)"

# Compilar todo
all: $(BINS)

# Regla patrón: src/capX/foo.c -> bin/capX/foo
$(BIN_DIR)/%: $(SRC_DIR)/%.c | $$(@D)
	$(CC) $(CFLAGS) $< -o $@

# Crear carpeta destino si no existe
$$(@D):
	mkdir -p $@

# Targets por capítulo: cap1, cap2, ...
$(foreach c,$(CAPS),$(eval CAP$(c)_SRCS := $(wildcard $(SRC_DIR)/cap$(c)/*.c)))
$(foreach c,$(CAPS),$(eval CAP$(c)_BINS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(CAP$(c)_SRCS))))
$(foreach c,$(CAPS),$(eval cap$(c): $$\(CAP$(c)_BINS\)))

# Limpiar todo o solo un capítulo: clean-cap1, clean-cap2, ...
clean:
	rm -rf $(BIN_DIR)

clean-%:
	rm -rf $(BIN_DIR)/$*
