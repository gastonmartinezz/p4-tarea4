# Compilador
CXX = g++

# Opciones del compilador
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Directorio de los archivos fuente
SRC_DIR = lab0

# Directorio de los archivos de inclusión
INC_DIR = $(SRC_DIR)/include

# Archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Nombre del ejecutable
TARGET = programa

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $^ -o $@

clean:
	rm -f $(TARGET)
