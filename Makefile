# Define the compiler
CC = g++

# Define the directories
INCLUDE_DIR = include
SRC_DIR = src
PRESENTACION_DIR = presentacion
BUILD_DIR = build

# Define the output executable
OUTPUT = main

# Collect all the source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/Controladores/*.cpp $(SRC_DIR)/DataTypes/*.cpp $(PRESENTACION_DIR)/*.cpp main.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))
OBJ_FILES := $(patsubst $(PRESENTACION_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(OBJ_FILES))
OBJ_FILES := $(patsubst main.cpp, $(BUILD_DIR)/main.o, $(OBJ_FILES))

# Define the include flags
INCLUDE_FLAGS = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/Controladores -I$(INCLUDE_DIR)/DataTypes -I$(INCLUDE_DIR)/Interfaces

# Define the compile flags
CFLAGS = -Wall -g $(INCLUDE_FLAGS)

# Define the linker flags
LDFLAGS =

# Rule to build the output executable
$(OUTPUT): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(OUTPUT) $(LDFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(PRESENTACION_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -rf $(BUILD_DIR)/*.o $(OUTPUT)

# Phony targets
.PHONY: clean
