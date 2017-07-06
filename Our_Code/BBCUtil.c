//BBCUtil.c

#include "ByteBlock.h";
#include "BBCUtil.h";

//This function starts a new run based on the type of byte we have
//all 'binary' values here are still very much pseudo code.
//real values will be stored in our defined 'typedef char byte' type

void startNewRun(blockSegBBC *param){

  //first we should write out the current array of chars to file,
  //and also free the memory from that array
  //fwrite(param->curr_run ...... etc.);

  //ZERO FILL
  //there's only one possible byte we should produce TYPE_1
  if(param->byte_type == ZERO_BYTE)
    param->header = 0b10010000;
	  param->fill_len = 1;
    param->tail_len = 0;
    param->run_type = TYPE_1;
    param->fill_bit = 0b00000000;

  //ONE_FILL
  //there's only one possible byte we should produce TYPE_1
  if(param->byte_type == ONE_BYTE)
    param->header = 0b11010000;
    param->fill_len = 1;
    param->tail_len = 0;
    param->run_type = TYPE_1;
    param->fill_bit = 0b11111111;

  //ODD BYTE
  if(param->byte_type == ODD_BYTE)
    //make (and end) type 2 run with the odd bit stored in the header
    param->header = 0b01000000;
    //here we decide the last three bits of the above binary number
    param->header = placeOddBit(param);

  //MESSY BYTE... for example, 01101010
  if(param->byte_type == MESSY_BYTE)
    //start off with a type 1 run, fill_length = 0.
    param->header = 0b1X000001;
    //store the header byte and the literal in the run
    param->curr_run = {'1X000001', '01101010'};
  }

//changes the run type (either type 1 to type 2 or type 3 to type 4)
void changeRunType(int run_type, blockSegBBC *param){

  /*this only happens if we are already a TYPE_1 run AND the
  tail length is 0 (i.e. going from type 1 to type 2)*/
  if(run_type == TYPE_2){
    //we want to preserve: fill bit and the fill_length.
    //get the odd bit position from
    param->header = '01' + fill_bit + fill_length + odd_bit_pos
  }
  // if a type 1 ever max's out the fill_length than it must be changed to a type 3
  else if(run_type == TYPE_3)
  {
    param->header = '001' + fill_bit + tail_length //counter bytes will follow
  }

  /*this only happens if we are already a TYPE_3 run AND the
  tail length is 0 (i.e. going from type 3 to type 4)*/
  else if(run_type == TYPE_4){
	//we want to preserve: fill bytes and the fill_length.
    param->header = '0001' + fill_bit + odd_bit_pos  //counter bytes will follow
  }

}

//do some binary shifting here
byte placeOddBit(blockSegBBC *param){
  //next_byte is one of eight bytes
  char the_byte = param->next_byte;
  int i = 0;
  int pos = 0;
  //shift right until the number == 1
  for(i = 0; i < 8; i++){
    if(the_byte == 1){
      pos = i;
      break;
    }
    else{
      the_byte >>= 1;
    }
  }
  param->header |= pos;
  return param->header;
}

//increments the fill length in the header
//increments the fill length in a type 1 run
//increments the counter bytes in a type 3 run
void incrementFill(blockSegBBC *param){
  if(param->run_type == TYPE_1){
    unsigned char temp = param->header;s
    temp <<= 2;
    temp >>= 6;
    temp = temp + 1;
    temp <<= 6;
    unsigned char newhead = 0b10000000;
    newhead |= temp;
    param->header = newhead;
    param->fill_len = param->fill_len + 1;

  }
  //complex
  if(param->run_type == TYPE_3){

  }
}

//gets the type of a RAW byte
unsigned int getType(next_byte){
  unsigned char b = next_byte;
  if(next_byte == 0){
    return ZERO_FILL;
  }
  else if(next_byte == 255){
    return ONE_FILL;
  }
  //more efficient way to do this? ask david
  else if(b == 1 || b == 2 || b == 4 || b == 8 || b == 16 || b == 32 || b == 64 || b == 128){
    return ODD_BYTE;
  }
  else{
    return MESSY_BYTE;
  }
}

//increases tail_len in header by one
//concatenates a literal byte to the tail of curr_run
//This funtion should only be used for types 1 and 3 where the tail length is guarented to be the last 4 bits of the header
unsigned int incrementTail(blockSegBBC *param){

  if(param->run_type == TYPE_2 || param->run_type == TYPE_4)
  {
    printf("ERROR: incrementing tail when run type is of type 2 or 4!!!");
  }
  else
  {
    unsigned char temp = param->header; //copy header byte into temp value
    temp <<= 4; //clear first half of temp, use left shitf bitwise operation by 4
    temp >>= 4; //move tail bits to LSBs position in temp, this way we can view the actual value of the tail length, use right shitf bitwise operation by 4
    temp += 1; //increment tail length by 1

    param->header >>= 4; //clear out the old tail length bits from header
    header |= temp; //add the new tail length to header using an or bitwise operation
  }



}

/*
void getRunType(){

}

//either ZERO_FILL or ONE_FILL 00000000 or 11111111
void getFillByte(){

}

void getNextByte(blockSegBBC *param){

}


unsigned int getFillLen(unsigned char header, unsigned char runtype){

}

unsigned int getTailLen(){

}
*/
