//bbcUtil.h
#include "blockSegBBC.h"

#define ZERO_BYTE 0
#define ONE_BYTE 1
#define ODD_BYTE 2
#define MESSY_BYTE 3

#define TYPE_1 0
#define TYPE_2 1
#define TYPE_3 2
#define TYPE_4 3

#define FILL_LIMIT 3 //maybe????
#define TAIL_LIMIT 15 //maybe could be 16

typedef char byte;

void startNewRun(blockSegBBC *param);

void changeRunType(int run_type, blockSegBBC *param);

byte placeOddBit(blockSegBBC *param);

void incrementFill(blockSegBBC *param);

unsigned int getType(next_byte);

unsigned int incrementTail(blockSegBBC *param);
