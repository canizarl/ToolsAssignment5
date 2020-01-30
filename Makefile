# compiler variables
CC = gcc
CFLAGS = -Wall -g

# custom variables
objectsRound = round.o parse.o
objectsSeq = my_seq.o parseSeq.o
objectsGrep = my_grep.o parseGrep.o
objectsHexd = my_hexdump.o parseHexd.o

# Question 1 ROUND 
round: $(objectsRound)
	$(CC) $(CFLAGS) -o round $(objectsRound)

round.o: round.c parse.h
	$(CC) $(CFLAGS) -c round.c

parse.o: parse.c parse.h
	$(CC) $(CFLAGS) -c parse.c




# Question 2 MY_SEQ
my_seq: $(objectsSeq)
	$(CC) $(CFLAGS) -o my_seq $(objectsSeq)

my_seq.o: my_seq.c parseSeq.h
	$(CC) $(CFLAGS) -c my_seq.c

parseSeq.o: parseSeq.c parseSeq.h
	$(CC) $(CFLAGS) -c parseSeq.c




# Question 3 MY_GREP
my_grep: $(objectsGrep)
	$(CC) $(CFLAGS) -o my_grep $(objectsGrep)

my_grep.o: my_grep.c parseGrep.h
	$(CC) $(CFLAGS) -c my_grep.c

parseGrep.o: parseGrep.c parseGrep.h
	$(CC) $(CFLAGS) -c parseGrep.c




# Question 4 MY_HEXDUMP
my_hexdump: $(objectsHexd)
	$(CC) $(CFLAGS) -o my_hexdump $(objectsHexd)

my_hexdump.o: my_hexdump.c parseHexd.h
	$(CC) $(CFLAGS) -c my_hexdump.c

parseGrep.o: parseHexd.c parseHexd.h
	$(CC) $(CFLAGS) -c parseHexd.c




.PHONY: 
clean:
	$(RM) round $(objectsRound)
	$(RM) round $(objectsSeq)
	$(RM) round $(objectsGrep)
	$(RM) round $(objectsHexd)
