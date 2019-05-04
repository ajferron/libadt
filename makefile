CC = gcc
FLAGS = -Wall -Iinclude
SOURCES = $(filter-out src/test.c, $(wildcard src/*.c))
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))

libadt.a: $(OBJECTS)
	ar cr lib/libadt.a obj/*.o

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

adt_test: libadt.a src/main.c
	$(CC) $(FLAGS) -c src/main.c -o obj/main.o
	$(CC) obj/main.o lib/libadt.a -o bin/adt_test

clean:
	rm -rf obj/* bin/* lib/libadt.a
