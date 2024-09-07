APP_NAME = gameengine

# Toolchain definitions
CC  = gcc
CXX = g++
AS  = as
LD  = ld
OC  = objcopy
OD  = objdump
OS  = size

# Directories
SRC_D = src
BUILD_D = build
MODULES = Components ECS Entities Game Logger Systems

# Compiling flags & linking flags
INCLUDE  = -Ilibs
CXXFLAGS = -Wall -g -O2 -std=c++17
LDFLAGS  = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3
# Source files
SRC_DIRS = $(addprefix $(SRC_D)/,$(MODULES)) $(SRC_D)
BUILD_DIRS = $(addprefix $(BUILD_D)/,$(MODULES)) $(BUILD_D)
SRCS  = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
OBJS  = $(patsubst $(SRC_D)/%.cpp,$(BUILD_D)/%.o,$(SRCS))
TARGET = $(BUILD_D)/$(APP_NAME)

.PHONY: all
all: $(BUILD_DIRS) | $(TARGET)

$(BUILD_DIRS):
	@mkdir -p $@

$(BUILD_D)/%.o: $(SRC_D)/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $< -o $@
	@echo ""

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@
	@echo ""

.PHONY: clean
clean:
	@rm -rf $(BUILD_D)

.PHONY: run
run: $(TARGET)
	@chmod +x $(TARGET)
	./$(TARGET)
