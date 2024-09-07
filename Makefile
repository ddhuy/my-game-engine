APP_NAME = gameengine

# Toolchain definitions
CC  = gcc
CXX = g++
AS  = as
LD  = ld
OC  = objcopy
OD  = objdump
OS  = size

# Compiling flags & linking flags
INCLUDES = -Ilibs
CXXFLAGS = -Wall -g -O2 -std=c++17
LDFLAGS  = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3
# Directories
SRC_DIR = src
SRC_DIRS =	$(SRC_DIR) \
			$(SRC_DIR)/Components \
			$(SRC_DIR)/ECS \
			$(SRC_DIR)/Entities \
			$(SRC_DIR)/Game \
			$(SRC_DIR)/Logger \
			$(SRC_DIR)/Systems

BIN_DIR = build
BIN_DIRS = $(patsubst $(SRC_DIR)/%,$(BIN_DIR)/%,$(SRC_DIRS))

# Source & Object files
SRCS  = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
OBJS  = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/$(APP_NAME)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@
	@echo ""

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $< -o $@
	@echo ""

.PHONY: clean
clean:
	@rm -rf $(BIN_DIR)

.PHONY: run
run: $(TARGET)
	@chmod +x $(TARGET)
	./$(TARGET)
