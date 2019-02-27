CC = gcc
FLAGS = -Wall -Iinclude
SOURCES = $(filter-out src/test.c, $(wildcard src/*.c))
OBJECTS = $(patsubst src/%.c, obj/%.o, $(SOURCES))

abslib.a: $(OBJECTS)
	ar cr ./bin/abslib.a obj/*.o

obj/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

test: abslib.a src/test.c
	$(CC) $(FLAGS) -c src/test.c -o obj/test.o
	$(CC) obj/test.o ./bin/abslib.a -o ./bin/test

clean:
	rm -rf ./obj/* ./bin/*
