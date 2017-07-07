test:
	gcc -Wall -o bintest binarytest.c

cleantest:
	rm -f *.o bintest

all:
	gcc -Wall -c BBCUtil.c
	gcc -Wall -c BBCCompressor.c
	gcc -Wall -o main  BBCUtil.o BBCCompressor.o  -lm