#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Here's the problem source. 'The 0x10 Best Questions|C test
  // I thought it had the promotion rules wrong in regard to signed/unsigned
  //  Heres the money where the mouth is... I was wrong.
  // TODO check format specifiers for sillyness
  
  
  printf("================================================\n\n");
  printf("Shorthand follows literal unless stated\n");
  printf("unsigned char: uc\n");
  printf("unsigned int: ui\n");
  printf("================================================\n\n");
  
  
  unsigned char A = 2;
  int B = -4;
  printf("The following should be the only signed operation\n");
  printf("  Due to sizeof(unsigned int) < sizeof(int)\n");
  printf("================================================\n\n");
  printf("-4i - 2uc = \tSigned:%i : \tUnSigned:%u\n", (B-A), (B-A));
  printf("2uc - -4i = \tSigned:%i : \tUnSigned:%u\n\n", (A-B), (A-B));
  
  printf("The following should be only unsigned operations\n");
  printf("  Due to sizeof(unsigned Type) >= sizeof(int)\n\n");
  printf("================================================\n\n");
  unsigned int C = 2;
  int D = -4;
  printf("-4i - 2ui = \tSigned:%i : \tUnSigned:%u\n", (D-C), (D-C));
  printf("2ui - -4i = \tSigned:%i : \tUnSigned:%u\n\n", (C-D), (C-D));
  
  unsigned long E = 2;
  int F = -4;
  printf("-4i - 2ul = \tSigned:%i : \tUnSigned:%u\n", (F-E), (F-E));
  printf("2ul - -4i = \tSigned:%i : \tUnSigned:%u\n", (E-F), (E-F));

  return EXIT_SUCCESS;
}