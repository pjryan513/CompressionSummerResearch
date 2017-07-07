test:
	gcc -Wall -o bintest binarytest.c

cleantest:
	rm -f *.o bintest

bbc:
	gcc -Wall -c ActiveWord.c
	gcc -Wall -c Clock.c
	gcc -Wall -c Query.c
	gcc -Wall -c QueryUtil.c
	gcc -Wall -c RawBitmapReader.c
	gcc -Wall -c SegUtil.c
	gcc -Wall -c VALCompressor.c
	gcc -Wall -c VALQuery.c
	gcc -Wall -c WAHCompressor.c
	gcc -Wall -c WAHQuery.c
	gcc -Wall -c Writer.c
	gcc -Wall -c BBCUtil.c
	gcc -Wall -c BBCCompressor.c
	gcc -Wall -o main main.c ActiveWord.o Clock.o Query.o QueryUtil.o RawBitmapReader.o SegUtil.o VALCompressor.o VALQuery.o WAHCompressor.o WAHQuery.o Writer.o BBCUtil.o BBCCompressor.o -lpthread -lm