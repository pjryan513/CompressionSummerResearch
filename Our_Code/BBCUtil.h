//bbcUtil.h
#include <stdio.h>
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

typedef unsigned char byte;

void startNewRun(struct blockSegBBC *param);

void changeRunType(int run_type, struct blockSegBBC *param);

void placeOddBit(struct blockSegBBC *param);

void incrementFill(struct blockSegBBC *param);

unsigned int getType(unsigned char next_byte);

unsigned int incrementTail(struct blockSegBBC *param);
