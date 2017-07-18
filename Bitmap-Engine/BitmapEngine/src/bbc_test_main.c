#include <stdio.h>
#include <stdlib.h>
#include "BlockSeg.h"

int main()
{
  printf("start of main\n");
  struct blockSeg *segtest1;
  struct blockSeg *segtest2;
  struct blockSeg *segtest3;
  struct blockSeg *segtest4;

  segtest1 = (blockSeg*) malloc(sizeof(blockSeg));
/////////////////for possibly writing an actual text file and reading it///////////////
    /*segtest2->
  	int i;
	for(i=0;i<colsPerFile;i++){

		saving[i]->toCompress = (word_read *) malloc(sizeof(word_read)*(block/colsPerFile));
		saving[i]->size=fread(saving[i]->toCompress,sizeof(word_read),block/colsPerFile,toRead);*/
  int i;
  int tnum = 4;

  //TEST #1 (WORKING)
  //00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
  if(tnum == 0){
  	segtest1->size = 10;
  	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*10);
	for(i = 0; i < segtest1->size; i++)
	{
	  segtest1->toCompress[i] = 0;
	}
  }
  //TEST #2 (WORKING)
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
  //TEST #3 (W0RKING)
  //00000000 00000000 00000000
  else if(tnum == 2){
  	segtest1->size = 3;
  	segtest1->toCompress = (word_read*) malloc(sizeof(word_read)*3);
	for(i = 0; i < 3; i++)
	{
	  segtest1->toCompress[i] = 0;
	}
  }

  //TEST #4 (WORKING)
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

    //TEST #5 (????????)
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

      //TEST #6 (????????)
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
  //TEST #7 (????????)
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
  FILE *ptr = fopen("bbc_test_output.dat","wb");
  //FILE *readfrom2 = fopen("")
  segtest1->colFile = ptr;

  printf("colFile is pointing\n");
  bbcCompress(segtest1);

  free(segtest1->toCompress);
  free(segtest1);
}
