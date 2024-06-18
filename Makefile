# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

# Directorios
SRC_DIR = src
INC_DIR = include
PRESENTACION_DIR = presentacion
OBJ_DIR = obj
BIN_DIR = bin

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(PRESENTACION_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
OBJS := $(patsubst $(PRESENTACION_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(OBJS))

# Ejecutable
EXEC = $(BIN_DIR)/programa

# Regla principal
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PRESENTACION_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Directorios de salida
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpiar archivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
