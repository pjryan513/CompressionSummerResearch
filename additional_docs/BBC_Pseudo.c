Revisted Psudeo Code


while(get next byte)

  char next_byte= getNextByte()

  int next = getType(next_byte)
  //these methods gather information from the header
  //default to type 1 run
  fill_len = getFill();
  tail_len = getTail();
  //Run Types (as Described in our documentation and BBC paper)
  //'0' = TYPE_1
  //'1' = TYPE_2
  //'2' = TYPE_3
  //'3' = TYPE_4
  run_type = getHeadType(); //can also be "4" (or something....) to represent a new run
  //New run:
  //0 not new run
  //1 new run
  new_run = isNewRun(); //TRUE or FALSE
  fill_byte = getFillByte(); //either ZERO_FILL or ONE_FILL 00000000 or 11111111

/**
***FUNCTION DOCUMENTATION***
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
      startNewRun();

*/

  //0-fill byte or 1-fill byte (11111111 or 00000000)
  if(next == 0 || next == 1)

    if(new_run)

      if(next == 0)
        setFillBit(0);

      else
        setFillBit(1);

      new_run == 0;

    if(next == fill_byte)

      if(run_type == TYPE_1)

        if(fill_len < 3)
          incrementFill();

        else
          //change to type 3 run
          //COMPLICATED!!
          //changeHeaderType(int type)
          chageHeaderType(TYPE_3);

      else if(run_type = TYPE_3)
        //increment the counter byte somehow
        //COMPLICATED!! (need more overhead)
        incrementCounterByte();

    else
      startNewRun();


  //odd byte (Eg: 00010000)
  if(next==2)
    if(new_run)
      changeHeaderType(TYPE_2);
      placeOddBit(next_byte);
      new_run == 0;

    if(tail_length > 0) //end the current run and make a new type 2 run
      makeOddHeader(next_byte);
      startNewRun();
      //end current run and create a new type 2 run holding just the odd byte

    if(run_type == TYPE_1)
      changeHeaderType(TYPE_2);
      placeOddBit(next_byte);

    if(run_type == TYPE_3)
      changeHeaderType(TYPE_4);
      placeOddBit(next_byte);


  //messy byte (Eg: 11010100)
  if(next==3)

    if(new_run) 
      //start a new type 1 run
      //this method increases the tail length bit in the header and concatenates the messy literal bit to the tail
      incrementTail(next_byte);
      new_run == 0;

    else if(run_type == TYPE_1)

      if(tail_length<15)

        incrementTail(next_byte);

      else

        incrementTail(next_byte);

    else if(run_type == TYPE_3)

      if(tail_length<15)

        incrementTail(next_byte);
        startNewRun();

      else

        incrementTail(next_byte);
        startNewRun();






