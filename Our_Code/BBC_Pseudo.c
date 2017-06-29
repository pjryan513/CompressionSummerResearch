/**Revisted Psudeo Code**/
#include "bbcUtil.h";


void bbcCompress(bbcSeg *param){
  while(get next byte)

  char next_byte= getNextByte()

  int byte_type = getType(next_byte)
  //these methods gather information from the header
  if(header != NULL){
    fill_len = getFill();
    tail_len = getTail();
    run_type = getHeadType(); 
    fill_bit = getFillByte(); //actually represents the fill bit, saved as a byte to compare more easily
                              //either ZERO_FILL or ONE_FILL 00000000 or 11111111
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

      //
      //increases the tail length in the header and concatenates the messy literal bit to the tail of the run
      //@param char next_byte The literal byte to be concatenated
      incrementTail(char next_byte)

      //increments the fill length in the header
      incrementFill();

      //changes the current header type to the desired header type
      changeHeaderType(int type);

      //increments the counter bytes in a type 2 or type 4 run
      incrementCounterByte();

      //write current run to the compressed outfile
      //set header to NULL
      //start new run, create new header
      startNewRun(byte_type);

      //creates the 3 bits in type 2 or type 4 header to represent odd bit in last byte of tail
      placeOddBit();

      //in the case where after a tail, we run into an odd byte
      //places an odd byte header (type 2) in the compressed data before starting a new run (defaulting to a blank type 1 header)
      makeOddHeader();
*/
  //if the header is null
  if(header==NULL){
    startNewRun(byte_type);

  }

  //0-fill byte or 1-fill byte (11111111 or 00000000)
  else if(byte_type == ZERO_BYTE || byte_type == ONE_BYTE)

    //proper type of fill (0 or 1)
    if(byte_type == fill_bit)

      //if we are currently in a TYPE_1 run
      if(run_type == TYPE_1)

        //we're not too long yet, so stay as a TYPE_1 and incrememt
        if(fill_len < 3)
          incrementFill();

        //otherwise, change to type 3 run
        else
          changeRunType(TYPE_3);

      //if we are currently in a TYPE_3 run
      else if(run_type = TYPE_3)
        //increment the counter bytes
        incrementCounterByte();

    //if it's not the right kind of fill
    else
      startNewRun(byte_type);


  //odd byte (Eg: 00010000)
  else if(byte_type==ODD_BYTE)

    //if we are a TYPE_1 run
    if(run_type == TYPE_1)

      //change ourselves to a TYPE_2 run
      //this will end the current run
      changeRunType(TYPE_2);

    //if we are a TYPE_3 run
    if(run_type == TYPE_3)

      //change ourselves to a TYPE_4 run
      //this will end the current run
      changeRunType(TYPE_4);

  //messy byte (Eg: 11010100)
  else if(byte_type==3)

    //if we are a TYPE_1 run
    if(run_type == TYPE_1)

      if(tail_length<15)

        //if we aren't too long yet, add the 
        //messy bit to the tail and increment the tail length
        incrementTail(next_byte);

      else

        //otherwise, start a new run 
        startNewRun(byte_type);

    //if we are a TYPE_3 run
    else if(run_type == TYPE_3)

      //if we are not too long yet, add the 
      //messy bit to the tail and increment the tail length
      if(tail_length<15)

        incrementTail(next_byte);

      //otherwise, start a new run
      else

        startNewRun(byte_type);
}