#ifndef CONTROL_H_
#define CONTROL_H_

//#include <math.h>
//#include <sys/time.h>
#include "Vars.h"




//DEFINE HERE***************************************
#define CORE OUT_CORE								//IN_CORE or OUT_CORE (recommended: OUT_CORE)
#define BLOCK_SIZE 32								//kB blocks (recommended: 32)
#define MAX_NUM_THREADS 4								//define number of threads to use for compression (1,2,3,4)

#define COMPRESSION BBC					//define compression type (WAH, VAL, or BBC)
#define WORD_LENGTH 8							//define compression word length (32/64)
#define NUM_SEGS 1									//define number of segments per word to use (1/2/4 -> -1 runs optimal segment length)

//#define QUERY_FILE "Queries/query2.txt"				//the query file to be parsed
#define WRITE_TO_FILE 1								//write query results to file or not?
#define DECODE DECODE_UP							//for VAL: decode DECODE_UP or DECODE_DOWN
#define DEBUG 0
#define PRINT 0
//#define NUM_TRIALS 5
#define PAR_READ 1

//DEFINE HERE*************************************
#if COMPRESSION == WAH
	#define FLAG_BITS 1
	#if WORD_LENGTH == 32//WAH 32
		#define WORD_READ_LENGTH 32
		#define BASE_LEN 31
		typedef unsigned int word_32;
		typedef unsigned int word_read;
	#else//WAH 64
		#define WORD_READ_LENGTH 64
		#define BASE_LEN 63
		typedef unsigned long long word_32;
		typedef unsigned long long word_read;
	#endif
#elif COMPRESSION == BBC //8 bit words
	#define FLAG_BITS 0
	#define WORD_READ_LENGTH 8
	#define BASE_LEN 8
	typedef unsigned char byte;
	typedef unsigned char word_32;
	typedef unsigned char word_read;
	#endif
/*#else//VAL
	#define FLAG_BITS 4
	#if WORD_LENGTH == 32 //VAL 32
		#define WORD_READ_LENGTH 8
		#define BASE_LEN 7
		typedef unsigned int word_32;
		typedef char word_read;
	#else // VAL 64
		#define WORD_READ_LENGTH 16
		#define BASE_LEN 15
		typedef unsigned long long word_32;
		typedef unsigned short word_read;
	#endif*/


#endif /* CONTROL_H_ */
