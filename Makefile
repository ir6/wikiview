all: makeindex1

OBJS =
BINS =

makeindex1: makeindex1.o
	gcc -Wall $< -o $@

makeindex1.o: makeindex1.c
	gcc -Wall -O3 -c $< -o $@

OBJS += makeindex1.o
BINS += makeindex

clean:
	-rm $(OBJS) $(BINS)
