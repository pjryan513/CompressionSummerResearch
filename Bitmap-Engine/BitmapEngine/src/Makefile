# A note to aingerson, por que no Makefile?
all :
	gcc -Wall -c ActiveWord.c
	gcc -Wall -c BBCCompressor.c
	gcc -Wall -c BBCUtil.c
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
	gcc -Wall -o main main.c ActiveWord.o BBCCompressor.o BBCUtil.o Clock.o Query.o QueryUtil.o RawBitmapReader.o SegUtil.o VALCompressor.o VALQuery.o WAHCompressor.o WAHQuery.o Writer.o -lpthread -lm

bintest:
	gcc -Wall -o bintest binarytest.c

cleantest:
	rm -f *.o bintest

bbc: BBCUtil.o BBCCompressor.o

BBCUtil.o: BBCUtil.c
	gcc -Wall -c BBCUtil.c

BBCCompressor.o: BBCCompressor.c
	gcc -Wall -c BBCCompressor.c

bbc_test_main.o: bbc_test_main.c
	gcc -Wall -c bbc_test_main.c

clean:
	rm main
	rm *.o

cleanbbc:
	rm bbc_test_main
	rm *.o

bbctest:
	gcc -Wall -c ActiveWord.c
	gcc -Wall -c BBCCompressor.c
	gcc -Wall -c BBCUtil.c
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
	gcc -Wall -c bbc_test_main.c
	gcc -Wall -o bbc_test_main ActiveWord.o BBCCompressor.o BBCUtil.o bbc_test_main.o Clock.o Query.o QueryUtil.o RawBitmapReader.o SegUtil.o VALCompressor.o VALQuery.o WAHCompressor.o WAHQuery.o Writer.o -lpthread -lm