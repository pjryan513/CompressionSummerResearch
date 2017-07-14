#include <stdio.h>
#include <stdlib.h>
#include "BlockSeg.h"

int main()
{
  printf("start of main");
  struct blockSeg *seg;

  //seg = (blockSeg*) malloc(sizeof(blockSeg));

  //seg->size = 10;
  int i;

  for(i = 0; i < seg->size; i++)
  {
    seg->toCompress[i] = 0;
  }
  printf("segs is filled");

  //FILE *ptr = fopen("bbc_test_output.dat","wb");
  //seg->colFile = ptr;
  printf("colFile is pointing");
  bbcCompress(seg);

  free(seg);
}
