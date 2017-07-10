test:
	gcc -Wall -o bintest binarytest.c

cleantest:
	rm -f *.o bintest

all: BBCUtil.o BBCCompressor.o


BBCUtil.o: BBCUtil.c
	gcc -Wall -c BBCUtil.c

BBCCompressor.o: BBCCompressor.c
	gcc -Wall -c BBCCompressor.c

clean:
	rm -f *.o
