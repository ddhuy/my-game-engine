TARGET = gameengine 
SRC_DIR = src

# Toolchain definitions
CC  = gcc
CXX = g++
AS  = as
LD  = ld
OC  = objcopy
OD  = objdump
OS  = size

# Compiling flags & linking flags
INCLUDE  = -Ilibs
CXXFLAGS = -Wall -g -O2 -std=c++17
LDFLAGS  = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3
# Source files
SRCS  = $(wildcard $(SRC_DIR)/*.cpp)
OBJS  = $(SRCS:.cpp=.o)

.PHONY: all
all: $(TARGET)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) $< -o $@
	@echo ""

$(TARGET): $(OBJS)
	$(CXX) $^ $(LDFLAGS) -o $@
	@echo ""

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: run
run: $(TARGET)
	@chmod +x $(TARGET)
	./$(TARGET)

