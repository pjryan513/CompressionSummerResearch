//blockSegBBC.h
#ifndef BLOCKSEGBBC_H_
#define BLOCKSEGBBC_H_

#include "bbcUtil.h"

typedef struct blockSegBBC {
	unsigned int size;  //the size of the current block 
	byte *compressBytes; //the current block of uncompressed bytes
	struct blockBytes *nextBlock; //the next block of bytes to compress 
	unsigned int fill_len;
	unsigned int tail_len;
	unsigned int run_type;
	byte fill_bit;
	FILE *colFile; //the file we are writing our compressed bytes to
	byte next_byte;
	unsigned int byte_type;
	byte header;
	byte *curr_run; /*the current run (an array of bytes, in case we have literals, counter bytes, etc.)*/
	unsigned int curr_size; //the length of the curr_run array
}
