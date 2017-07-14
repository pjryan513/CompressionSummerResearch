#include <stdio.h>
#include <stdlib.h>
#include "BlockSeg.h"

int main()
{
  printf("start of main\n");
  struct blockSeg *seg;

  seg = (blockSeg*) malloc(sizeof(blockSeg));
  seg->toCompress = (word_read*) malloc(sizeof(word_read)*11);

  seg->size = 10;
  int i;

  for(i = 0; i < seg->size; i++)
  {
    seg->toCompress[i] = 0;
  }
  seg->toCompress[10] = 1;
  printf("segs is filled\n");

  FILE *ptr = fopen("bbc_test_output.dat","wb");
  seg->colFile = ptr;
  printf("colFile is pointing\n");
  bbcCompress(seg);

  free(seg->toCompress);
  free(seg);
}
