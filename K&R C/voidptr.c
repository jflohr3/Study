#include <stdio.h>
#include <stdlib.h>

// Source for this is 'https://www.interviewbit.com/embedded-c-interview-questions'

/* An unwieldly way to obtain partial chunks of a continous series of bits at
 *  an address...I'd just use a uchar pointer and ptr arithmetic.
 * I don't desire to ever use a pointer without an associated type unless
 *  otherwise impossible. Seems unnecessarily risky.
 */
int main()
{
  char mystring[] = "Never Confuse a Single Defeat with a Final Defeat";
  /* Other notable affirmations include:
   * "Fall seven times and stand up eight"
   * "Accomplishment uses diligence as a goal"
  */
  void* ptr = &mystring[0];
  /***************************************************************************** 
      I always disliked that the compiler complains if you use form
        *((*TYPE)ptr) for this kind of cast->dereference
      If there is no qualifier on the left of the *, it should apply to what is
        on the right. That's how const, volatile and the like operate...
  *****************************************************************************/
  printf("===============================System type sizes================\n");
  printf("myshort: \t%zu\nmyint:   \t%zu\nmylong: \t%zu\n",
         sizeof(short), sizeof(int), sizeof(long long));
  short myshort = *((short*)ptr);
  int myint = *((int*)ptr);
  long long mylong = *((long long*)ptr);
  
  
  printf("===============================Absolute Values==================\n");
  printf("myshort: \t%hi\nmyint:   \t%i\nmylong: \t%llu\n",
         myshort, myint, mylong);
  printf("================================================================\n\n");
  
  printf("===============================Hexadecimal Vals=================\n");
  printf("myshort: \t%X\nmyint:   \t%X\nmylong: \t%llx\n",
         myshort, myint, mylong);
  printf("===============================Exiting...=======================\n\n");
  return EXIT_SUCCESS;
}
