# compiler variables
CC = gcc
CFLAGS = -Wall -g

# custom variables
objects = round.o


round: $(objects)
	$(CC) $(CFLAGS) -o round $(objects)

round.o: round.c parse.h round.h
	$(CC) $(CFLAGS) -c round.c

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) -c parse.c




.PHONY: clean test
clean:
	$(RM) round $(objects)

