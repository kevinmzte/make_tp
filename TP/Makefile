# --- Compiladores y flags ---
CC      := gcc
CXX     := g++
CFLAGS  := -Wall -Wextra -std=c11
CXXFLAGS:= -Wall -Wextra -std=c++17

# --- Directorios ---
SRC_DIR := src
BIN_DIR := bin
CAPS    := 1 2 3 4 5

.PHONY: help all clean $(foreach c,$(CAPS),cap$(c)) clean-% $(foreach c,$(CAPS),listing%)

# --- Ayuda ---
help:
	@echo "Uso:"
	@echo "  make all            -> compila todos los capítulos"
	@echo "  make clean          -> borra todos los binarios"
	@echo "  make cap1           -> compila solo capítulo 1"
	@echo "  make clean-cap1     -> limpia solo capítulo 1"
	@echo "  make listing1.1     -> compila solo ese listing (ejecutable final)"

# --- Archivos fuente ---
SRCS_C   := $(wildcard $(SRC_DIR)/cap*/listing*.c)
SRCS_CPP := $(wildcard $(SRC_DIR)/cap*/listing*.cpp)

# --- Compilar .c a .o ---
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Compilar .cpp a .o ---
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- Ejecutables finales por capítulo ---
# listing1.1 depende de su .c y .cpp asociado
bin/%: $(BIN_DIR)/%.o $(BIN_DIR)/cap1/listing1.2.o
	@mkdir -p $(dir $@)
	$(CXX) $^ -o $@

# --- Targets por capítulo (todos los ejecutables de ese capítulo) ---
$(foreach c,$(CAPS), \
  $(eval CAP$(c)_EXES := $(patsubst $(SRC_DIR)/cap$(c)/listing%.c,$(BIN_DIR)/cap$(c)/listing%,$(wildcard $(SRC_DIR)/cap$(c)/listing*.c))) \
  $(eval cap$(c): $$(CAP$(c)_EXES)) )

# --- Compilar todo ---
all: $(foreach c,$(CAPS),cap$(c))

# --- Limpiar todos los binarios ---
clean:
	rm -rf $(BIN_DIR)

# --- Limpiar capítulo específico ---
clean-%:
	rm -rf $(BIN_DIR)/cap$*
