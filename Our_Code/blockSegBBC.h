//ByteBlock.h

typedef struct blockSegBBC {
	byte *compressBytes; //the current block of uncompressed bytes
	struct blockBytes *nextBlock; //the next block of bytes to compress 
	int fill_len;
	int tail_len;
	int run_type;
	byte fill_bit;
	FILE *colFile; //the file we are writing our compressed bytes to
	byte next_byte;
	int byte_type;
	byte header;
	byte *curr_run; /*the current run (an array of bytes, in case we have literals,
	counter bytes, etc.)*/
}
