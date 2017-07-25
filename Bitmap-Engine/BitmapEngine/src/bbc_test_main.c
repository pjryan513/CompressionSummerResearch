#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "BlockSeg.h"

int main(int argc, char*argv[])
{
  printf("start of main\n");

  int manualSet;
  if(argc == 0)
  {
    manualSet = 1;
  }
  else
  {
    manualSet = 0;
  }
  manualSet = 0; //testing

  struct blockSeg *segtest1;

  segtest1 = (blockSeg*) malloc(sizeof(blockSeg));


/////////////////for possibly writing an actual text file and reading it///////////////
    /*segtest2->
  	int i;
	for(i=0;i<colsPerFile;i++){

		saving[i]->toCompress = (word_read *) malloc(sizeof(word_read)*(block/colsPerFile));
		saving[i]->size=fread(saving[i]->toCompress,sizeof(word_read),block/colsPerFile,toRead);*/
  if(manualSet)
  {

    int i;
    int tnum = 10;

    //TEST #0 (WORKING)
    //00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
    if(tnum == 0){
    	segtest1->size = 10;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*10);
    	for(i = 0; i < segtest1->size; i++)
    	{
    	  segtest1->toCompress[i] = 0;
    	}
    }
    //TEST #1 (WORKING)
    //00000000 00000000 00000000 00010000
    else if(tnum == 1){
    	segtest1->size = 4;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*4);
    	for(i = 0; i < 3; i++)
    	{
    	  segtest1->toCompress[i] = 0;
    	}
    	segtest1->toCompress[3] = 0b00010000;
    	/*for(i = 4; i < segtest1->size; i++)
    	{
    	  segtest1->toCompress[i] = 0;
    	}*/
    }
    //TEST #2 (W0RKING)
    //00000000 00000000 00000000
    else if(tnum == 2){
    	segtest1->size = 3;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*3);
    	for(i = 0; i < 3; i++)
    	{
    	  segtest1->toCompress[i] = 0;
    	}
    }

    //TEST #3 (WORKING)
    //we need to figure out when to set fill_bit and fill_match correctly
    //also made a change to incrementFill because it automatically was setting the fill bit to 0 (not what we want)
    //11111111 11111111 11111111
    else if(tnum == 3){
    	segtest1->size = 3;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*3);
    	for(i = 0; i < 3; i++)
    	{
    	  segtest1->toCompress[i] = 0b11111111;
    	}
    }

      //TEST #4 (WORKING)
    //00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000010 00000000 00000000 00000000
    else if(tnum == 4){
    	segtest1->size = 14;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*14);
  	for(i = 0; i < 10; i++)
  	{
  	  segtest1->toCompress[i] = 0;
  	}
  	segtest1->toCompress[10] = 0b00000010;
  	for(i = 11; i < 14; i++)
  	{
  	  segtest1->toCompress[i] = 0;
  	}
    }

        //TEST #5 (WORKING)
    //00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 11111111 11111111
    else if(tnum == 5){
    	segtest1->size = 13;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*13);
    	for(i = 0; i < 10; i++)
    	{
    	  segtest1->toCompress[i] = 0;
    	}
    	segtest1->toCompress[10] = 0b00000000;
    	segtest1->toCompress[11] = 0b11111111;
    	segtest1->toCompress[12] = 0b11111111;

    }
    //TEST #6 (WORKING)
    //00000000 00000000 11111111 11111111
    else if(tnum == 6){
    	segtest1->size = 4;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*4);
    	for(i = 0; i < 2; i++)
    	{
    	  segtest1->toCompress[i] = 0;
    	}
    	segtest1->toCompress[2] = 0b11111111;
    	segtest1->toCompress[3] = 0b11111111;

    }
    //TEST #7
    //11111111 11111111 11010010 11101011 (10000001)*13
    else if(tnum == 7){
    	segtest1->size = 19;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*19);
    	for(i = 0; i < 2; i++)
    	{
    	  segtest1->toCompress[i] = 0b11111111;
    	}
    	segtest1->toCompress[2] = 0b11010010;
    	for(i = 3; i < 6; i++)
    	{
    	  segtest1->toCompress[i] = 0b11101011;
    	}
    	for(i = 6; i < 19; i++)
    	{
    		segtest1->toCompress[i] = 0b10000001;
    	}
    }
    //TEST #8
    //00000000
    else if(tnum == 8){
    	segtest1->size = 1;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*1);
    	segtest1->toCompress[0] =  0b00000000;

    }
    //TEST #9
    //11110111
    else if(tnum == 9){
    	segtest1->size = 1;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*1);
    	segtest1->toCompress[0] =  0b11110111;

    }

    //TEST #10
    //11111111 11111111 11111111 11011111
    else if(tnum == 10){
    	segtest1->size = 4;
    	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*4);
    	for(i = 0; i < 3; i++)
    	{
    		segtest1->toCompress[i] = 0b11111111;
    	}
    	segtest1->toCompress[3] =  0b11011111;

    }
  }
  else
  {
    printf("about to open tester2.dat\n");
    char cwd[1024];
    //char test[100];
    getcwd(cwd, sizeof(cwd));
    strcat(cwd, "/bbc_tester_2.dat");
    printf("%s\n", cwd);
    //FILE *inPtr = fopen("C:/Users/bill/Documents/Summer2017/Bitmap Project/CompressionSummerResearch/Develop/Bitmap-Engine/BitmapWorkloadGenerator/src/bitmap_out.txt","rb");
    FILE *inPtr = fopen(cwd,"rb");


    printf("about to read from bitmap_test.dat\n");
    int readSize = 8;
    int i;
    //int loopSize = 3000/8;
    fseek(inPtr, 0L, SEEK_END);
    int loopSize = ftell(inPtr);
    rewind(inPtr);

    segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*loopSize);
    segtest1->size = loopSize;
    printf("loopsize: %d\n", loopSize);
    for(i = 0; i < loopSize; i++)
    {
      //printf("inside loop\n");
      //unsigned char buff[1];
      fread(segtest1->toCompress, 1, loopSize, inPtr);
      //fread()
      //fgets(buff,readSize,inPtr);
      //segtest1->toCompress[i] = buff;
      printf("%02x", segtest1->toCompress[i]);
    }
    printf("\nloop end\n");



  }

  printf("here!!!!!!!!!!!!!\n");

  FILE *ptr = fopen("bbc_test_output.dat","wb");
  //FILE *readfrom2 = fopen("")
  segtest1->colFile = ptr;

  printf("colFile is pointing\n");
  bbcCompress(segtest1);

  free(segtest1->toCompress);
  free(segtest1);
}
