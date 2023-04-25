/******************************************************************************
 * we must do another exercise before retiring to watch the King go up 3-1 on
 * the self-proclaimed Kings. (NBA playoffs)
 * 
 * Implement atoi
 * May have the name wrong.
 * Take input string of a natural number and turn it into a integer 
 *  representation
 * Take any num of inputs, handle a min amount of foolery in args with warning
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
 * while there is still another argument to translate
 *  while there is still a char in the current working argument
 *    translate this digit to its value in base-10
 *    multiple the running count by the base, and add this value to it
 *  print the value to console with input string
 *  increment to next argument and reset locals for proc
 */

int main(int argc, char *argv[])
{
  size_t num_bytes = sizeof(long);
  printf("================================================================\n");
  printf("you handed me arguments:\n");
  for(int i=0; i<argc;++i)
    printf("arg %d:%s\n", i, argv[i]);
 
  if(argc<2) 
  {
    printf("I need at least one arg brother\n");
    printf("Feed me as many as you please, that may fit in a signed long\n");
    printf("Whereas signed long is of byte width:%zu\n\n", sizeof(long));
    printf("So give me numbers between [-%g, %g], inclusive",\
           pow(2, ((num_bytes*8)-1)), pow(2, ((num_bytes*8)-1))-1);
    return EXIT_FAILURE; 
  }
  
  int arg_idx = 0;
  int digit_val = 0;
  long result = 0;
  
  printf("==========================Starting...===========================\n");
  
  for(arg_idx=1; arg_idx<argc; ++arg_idx) 
  { // for each arg besides the first (prog name)
    for(int i=0; *(argv[arg_idx]+i) != '\0'; ++i)
    {
      digit_val = *(argv[arg_idx]+i) - '0'; // get this digits unit's place val
      result = result*10 + digit_val;
    }
    // end of char stream for this arg print result
    printf("arg:%d\t input:%s\t result:%li\n\n", \
           arg_idx, argv[arg_idx], result);
    result=0;
  }
  
  printf("==========================Finished...===========================\n");
  return EXIT_SUCCESS;
}
