//binarytest.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char*argv[]) {
	printf("Printing some numbers...\n");
	unsigned char a = 'a';
	printf("%x\n", a);
	unsigned char f = 0b01100001;

	printf("%x\n", f);
  unsigned char temp = 0b10010000;
  temp <<= 2;
  temp >>= 6;
  unsigned int newtemp = (unsigned int)temp;
  newtemp = newtemp + 1;
  unsigned char final = (unsigned char)newtemp;
  printf("Added Char: %x\n", final);
  final <<= 6;
  printf("Char after shift %x\n", final);
}

	

void printbincharpad(char n)
{
	while (n) {
	    if (n & 1)
	        printf("1");
	    else
	        printf("0");

	    n >>= 1;
	}
	printf("\n");
}
/**
**Revisted Psudeo Code**
#include "bbcUtil.h";


void bbcCompress(blockSegBBC *param){

  //these methods gather information from the header
  int blockSize = param->size;
  int i;
  for(i = 0; i < blockSize; i++)
  {

    param->next_byte= param->nextBlock[i];

    param->byte_type = getType(param->next_byte);
    //default to type 1 run
    if(header != NULL){
      param->fill_len = getFill(param->header);
      param->tail_len = getTail(param->header);
      param->run_type = getHeadType(param->header);
      //either ZERO_FILL or ONE_FILL 00000000 or 11111111
      param->fill_bit = getFillByte(param->header); //actually represents the fill bit, saved as a byte to compare more easily
    }
  /**
  ***FUNCTION DOCUMENTATION***

        //Run Types (as Described in our documentation and BBC paper)
        //'0' = TYPE_1
        //'1' = TYPE_2
        //'2' = TYPE_3
        //'3' = TYPE_4

        //takes a byte and decides what "type" of byte it is
        getType(next byte)

        //increases the tail length in the header and concatenates the messy literal bit to the tail of the run
        //@param char next_byte The literal byte to be concatenated
        incrementTail(char next_byte)

        //increments the fill length in the header
        incrementFill();

        //changes the current run type to the desired header type
        changeRunType(int type);

        //increments the counter bytes in a type 2 or type 4 run
        incrementCounterByte();

        //write current run to the compressed outfile
        //set header to NULL
        //start new run, create new header
        startNewRun(byte_type);

        //creates the 3 bits in type 2 or type 4 header to represent odd bit in last byte of tail
        placeOddBit(byte next_byte);

        //in the case where after a tail, we run into an odd byte
        //places an odd byte header (type 2) in the compressed data before starting a new run (defaulting to a blank type 1 header)
        makeOddHeader();
  */
/*
    //if the header is null
    if(param->header==NULL){
      startNewRun(param->byte_type);
    }

    //0-fill byte or 1-fill byte (11111111 or 00000000)
    else if(param->byte_type == ZERO_BYTE || param->byte_type == ONE_BYTE)

      //proper type of fill (0 or 1)
      if(param->byte_type == param->fill_bit)

        //if we are currently in a TYPE_1 run
        if(param->run_type == TYPE_1)

          //we're not too long yet, so stay as a TYPE_1 and incrememt
          if(param->fill_len < FILL_LIMIT)
            incrementFill();

          //otherwise, change to type 3 run
          else
            changeRunType(TYPE_3);

        //if we are currently in a TYPE_3 run
        else if(param->run_type = TYPE_3)
          //increment the counter bytes
          incrementCounterByte();

      //if it's not the right kind of fill, start a new run
      else

        startNewRun(param->byte_type);

    //odd byte (Eg: 00010000)
    else if(param->byte_type==ODD_BYTE)
      /*if the tail_length is 0, we can easily change to
      either a TYPE_2 or TYPE_4 run by concatenating the
      ODD_BYTE to the end of our fill. 
      if(param->tail_len == 0)

        //if we are a TYPE_1 run
        if(param->run_type == TYPE_1)

          //change ourselves to a TYPE_2 run
          //this will end the current run
          changeRunType(TYPE_2);

        //if we are a TYPE_3 run
        if(param->run_type == TYPE_3)

          //change ourselves to a TYPE_4 run
          //this will end the current run
          changeRunType(TYPE_4);

      /*if we already have a tail, we must start a new run using
      the ODD_BYTE
      //the startNewRun() function checks for this specific case
      else
        startNewRun(param->byte_type);

    //messy byte (Eg: 11010100)
    else if(param->byte_type==TYPE_4)

      //if we are a TYPE_1 run
      if(param->run_type == TYPE_1)

        if(tail_length<TAIL_LIMIT)

          //if we aren't too long yet, add the
          //messy bit to the tail and increment the tail length
          incrementTail(param->next_byte);

        else

    /*if we already have a tail, we must start a new run using
    the ODD_BYTE
    //the startNewRun() function checks for this specific case 
    else
      startNewRun(byte_type);

  //messy byte (Eg: 11010100)
  else if(byte_type==3)

          //otherwise, start a new run
          startNewRun(param->byte_type);

      //if we are a TYPE_3 run
      else if(param->run_type == TYPE_3)

        //if we are not too long yet, add the
        //messy bit to the tail and increment the tail length
        if(param->tail_length<TAIL_LIMIT)

          incrementTail(param->next_byte);

        //otherwise, start a new run
        else

          startNewRun(param->byte_type);
  }
}
*/