#include <stdio.h>
#include "Core.h"

int main(int argc, char *argsv[])
{
	printf("stuff");
  struct blockSeg *seg;

  seg->size = 10;
  int i;

  for(i = 0; i < seg->size; i++)
  {
    seg->toCompress[i] = 0;
  }

  FILE *ptr = fopen("bbc_test_output.dat","wb");
  seg->colFile = ptr;
  bbcCompress(seg);
}
