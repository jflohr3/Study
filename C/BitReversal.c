#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("You must supply one unsigned integer argument fitting in 32 bits\n\n");
  for(int i=0; i<argc; ++i)
    printf("arg %d: %s\n", i, argv[i]);
  printf("\n");
  
  if(argc != 2)
  {
    printf("You didn't supply one argument...\n\n");
    return EXIT_FAILURE;
  }
  printf("Sizeof uint here: %zu\n", sizeof(uint));
  printf("bytes\n\n");
  
  uint mask_MSB = (0x1<<31);
  uint mask_LSB = 0x1;
  
  unsigned int input = strtoul(argv[1], NULL, 10);
  unsigned int out = 0;
  printf("input    uint: 0x%X\n", input);
  while(input) // while still bits to be shifted
  {
    if(mask_MSB & input) // iff MSB set
      out = out | mask_LSB; // set correlating bit indexed from LSB
    mask_LSB <<= 1;
    input <<= 1;
  }
  
  printf("Reversed uint: 0x%X\n", out);
  
  return EXIT_SUCCESS;
}
