//BBCUtil.c

#include "ByteBlock.h";
#include "BBCUtil.h";

//This function starts a new run based on the type of byte we have
//all 'binary' values here are still very much pseudo code. 
//real values will be stored in our defined 'typedef char byte' type

startNewRun(blockSegBBC *param){

  //first we should write out the current array of chars to file, 
  //and also free the memory from that array
  fwrite(param->curr_run ...... etc.);

  //ZERO FILL
  //there's only one possible byte we should produce
  if(byte_type == ZERO_BYTE)
    //setFillBit(0);
    //makeHeader(byte_type);
    param->header = '10010000';
	fill_len = 1;

  //ONE_FILL
  //there's only one possible byte we should produce
  if(byte_type == ONE_BYTE)
    //setFillBit(1);
    param->header = '11010000';

  //ODD BYTE
  if(byte_type == ODD_BYTE)
    //make (and end) type 2 run with the odd bit stored in the header
    param->header = '01X00000';
    //here we decide the last three bits of the above binary number
    param->header = placeOddBit(param->next_byte);

  //MESSY BYTE... for example, 01101010
  if(byte_type == MESSY_BYTE)
    //start off with a type 1 run, fill_length = 0. 
    param->header = '1X000001';
    //store the header byte and the literal in the run
    param->curr_run = {'1X000001', '01101010'};
  }

//changes the run type (either type 1 to type 2 or type 3 to type 4)
changeRunType(int run_type){

  /*this only happens if we are already a TYPE_1 run AND the 
  tail length is 0 (i.e. going from type 1 to type 2)*/
  if(run_type == TYPE_2){
    //we want to preserve: fill bit and the fill_length. 
    //get the odd bit position from 
    param->header = '01' + fill_bit + fill_length 
  }

  /*this only happens if we are already a TYPE_3 run AND the 
  tail length is 0 (i.e. going from type 3 to type 4)*/
  else if(run_type == TYPE_4){
	//we want to preserve: fill bytes and the fill_length.
  }

}

//do some binary shifting here
placeOddBit(next_byte){

}

//increments the fill length in the header
//increments the counter bytes in a type 3 run
incrementFill();

//changes the current run type to the desired header type
changeRunType(int type);