TARGET = rxi.a

.PHONY: all
all: $(TARGET)

$(TARGET): log.o
	ar rcs $@ $^

log.o: log.c
	gcc -Wall -O2 -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)