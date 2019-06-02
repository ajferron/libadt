CC = gcc
FLAGS = -Wall -Iinclude
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

libadt.a: $(OBJS)
	ar crs bin/libadt.a $^

obj/%.o : src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj/* bin/* bin/libadt.a

