# compiler variables
CC = gcc
CFLAGS = -Wall -g

# custom variables
objects = round.o parse.o
objectsSeq = my_seq.o parseSeq.o

round: $(objects)
	$(CC) $(CFLAGS) -o round $(objects)

round.o: round.c parse.h
	$(CC) $(CFLAGS) -c round.c

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) -c parse.c

my_seq: my_seq.c parseSeq.h
	$(CC) $(CFLAGS) -o my_seq $(objectsSeq)

my_seq.o: my_seq.c 
	$(CC) $(CFLAGS) -c my_seq.c

parseSeq.o: parseSeq.c parseSeq.h
	$(CC) $(CFLAGS) -c parseSeq.c


.PHONY: clean test
clean:
	$(RM) round $(objects)
	$(RM) round $(objectsSeq)
