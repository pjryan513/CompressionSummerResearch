//ByteBlock.h

struct blockBytes {
	char *compressBytes; //the current block of uncompressed bytes
	struct blockBytes *nextBlock; //the next block of bytes to compress
	int fill_len;
	int tail_len;
	int run_type;
	char fill_bit;
	FILE *colFile; //the file we are writing our compressed bytes to
	char next_byte;
	int byte_type;
}