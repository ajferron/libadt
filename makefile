CC = gcc
FLAGS = -Wall -Iinclude
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))
LIBOBJS = $(filter-out obj/main.o, $(patsubst src/%.c, obj/%.o, $(SRCS)))

libadt.a: $(LIBOBJS)
	ar crs lib/libadt.a $^

adt_test: libadt.a obj/main.o
	$(CC) -o bin/adt_test obj/main.o -Llib -ladt 

obj/%.o : src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj/* bin/* lib/libadt.a
