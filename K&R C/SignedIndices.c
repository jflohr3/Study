/* 
  Here's the problem source.
    https://blog.robertelder.org/signed-or-unsigned-part-2
  I believe the blog may have misheard or bjarne incorrectly spoke,
    we all make mistakes... What matters is how we handle those mistakes.
*/
#include <stdio.h>
#include <stdlib.h>

int foo(void)
{
  return EXIT_SUCCESS;
}

int main()
{
  // Lets see what happens when we intentionally try to underflow
  //  a pointer of various types.
  
  // Type shouldn't matter but I'm not studying with the baggage of my own
  //  assumptions... Also it's trivial to test a few of them so...
  void*   ptr_void = 0x0;
  short*  ptr_short = 0x0;
  int*    ptr_int = 0x0;
  long*   ptr_long = 0x0;
  float*  ptr_float = 0x0;
  double* ptr_double = 0x0;
  
  int (*ptr_fn)(void) = &foo;
  ptr_fn = 0x0;
  
  printf("========Original================================================\n");
  printf("void: %p\tshort: %p\tint: %p\tlong: %p\tfloat: %p\tdouble: %p\t\
          fn: %p\n\n", ptr_void, ptr_short, ptr_int, ptr_long, ptr_float,\
          ptr_double, ptr_fn);
  printf("================================================================\n");
  
  ptr_void -= 0x1;
  ptr_short -= 0x1;
  ptr_int -= 0x1;
  ptr_long -= 0x1;
  ptr_float -= 0x1;
  ptr_double -= 0x1;
  ptr_fn -= 0x1;
  printf("========pointers of 0 after subtraction of 1====================\n");
  // NOTE
  //printf("void:  %p\tshort: %p\nint:   %p\tlong:  %p\nfloat: %p\tdouble:%p\n\
  //        fn:%p\n\n", ptr_void, ptr_short, ptr_int, ptr_long, ptr_float, ptr_double, ptr_fn);
  // Preprocessor don't care about preceding whitespace, use built in concat
  printf("void:  %p\tshort: %p\nint:   %p\tlong:  %p\nfloat: %p\tdouble:%p\n"
          "fn:    %p\n\n", ptr_void, ptr_short, ptr_int, ptr_long, ptr_float, ptr_double, ptr_fn);
  printf("================================================================\n");
  //gdb's online c++20 compiler & C compiler behave the same and as i'd expect. 
  // We underflow and the amount we do is defined by the type associated with the pointer.
  // I believe bjarne simply mispoke. Easily done when you feel strongly about
  //  an opinion that isn't widely accepted by your peers.
  
  printf("===========================Exiting...===========================\n\n");
  return EXIT_SUCCESS;
}
/* Here is further reading from the man himself 
    search for "P1428R0" if link broken...
    https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p1428r0.pdf
*/