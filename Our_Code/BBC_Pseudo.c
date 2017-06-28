/**Revisted Psudeo Code**/
#include "bbcUtil.h";

while(get next byte)

  char next_byte= getNextByte()

  int byte_type = getType(next_byte)
  //these methods gather information from the header
  //default to type 1 run
  if(header != NULL){
    fill_len = getFill();
    tail_len = getTail();
  //Run Types (as Described in our documentation and BBC paper)
  //'0' = TYPE_1
  //'1' = TYPE_2
  //'2' = TYPE_3
  //'3' = TYPE_4
    run_type = getHeadType(); 
    fill_bit = getFillByte(); //actually represents the fill bit, saved as a byte to compare more easily
  //either ZERO_FILL or ONE_FILL 00000000 or 11111111
  }
/**
***FUNCTION DOCUMENTATION***
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

      //sets new_run to TRUE and sets header to blank type 1 run (10000000)
      //write current run to the compressed outfile
      //set header to NULL
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

      if(run_type == TYPE_1)

        //confusing
        if(fill_len < 3)
          incrementFill();

        else
          //change to type 3 run
          //COMPLICATED!!
          //changeHeaderType(int type)
          changeRunType(TYPE_3);

      else if(run_type = TYPE_3)
        //increment the counter byte somehow
        //COMPLICATED!! (need more overhead)
        incrementCounterByte();

    else
      startNewRun(BYTE_TYPE);


  //odd byte (Eg: 00010000)
  else if(byte_type==ODD_BYTE)



      //end current run and create a new type 2 run holding just the odd byte

    if(run_type == TYPE_1)
      changeHeaderType(RUN_2);
      placeOddBit(next_byte);

    if(run_type == TYPE_3)
      changeHeaderType(TYPE_4);
      placeOddBit(next_byte);


  //messy byte (Eg: 11010100)
  else if(byte_type==3)

    if(run_type == TYPE_1)

      if(tail_length<15)

        incrementTail(next_byte);

      else

        startNewRun(byte_type);
        //incrementTail(next_byte);

    else if(run_type == TYPE_3)

      if(tail_length<15)

        incrementTail(next_byte);
        startNewRun();

      else

        //incrementTail(next_byte);
        startNewRun(byte_type);





startNewRun(char byte_type){
        if(byte_type == ZERO_BYTE)
          setFillByte(0);
          //makeHeader(byte_type);

       else
          setFillByte(1);


            if(new_run)
      changeHeaderType(TYPE_2);
      placeOddBit(next_byte);
      new_run == 0;
      makeOddHeader(next_byte);

//type 3
            incrementTail(next_byte);
            //this method increases the tail length bit in the header and concatenates the messy literal bit to the tail