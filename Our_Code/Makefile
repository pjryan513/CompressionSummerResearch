test:
	gcc -Wall -o bintest binarytest.c

cleantest:
	rm -f *.o bintest

all:
	gcc -Wall -c BBCUtil.c bbcUtil.h
	gcc -Wall -c BBCCompressor.c BBCCompressor.h blockSegBBC.h
	gcc -Wall -o main  BBCUtil.o BBCCompressor.o  -lm