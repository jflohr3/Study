/*******************************************************************************
 Meta Details 
• Using C++, provide code that simulates an elevator.
• Upload completed project to Github for discussion during interview.
• Document all assumptions and any features that weren’t implemented.
• The result should be an executable, or script, that can be run with the following inputs and generate the following outputs.

 Direct Requirements
• Inputs: [list of floors to visit] (e.g elevator start=12 floor=2,9,1,32)
• Outputs: [total travel time, floors visited in order] (e.g 560 12,2,9,1,32)
• Program Constants: Single floor travel time: 10

*******************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  /* Param check
   * Expect only inputs from the integer set
   */
   
  printf("================================================================\n");
  printf("you handed me arguments:\n");
  for(int i=1; i<argc;++i)
    printf("arg %d:%s\n", i, argv[i]);
  printf("================================================================\n");
 
  if(argc<2) 
  {
    printf("I need at least one arg brother\n");
    return EXIT_FAILURE; 
  }
  
  
  
  
  
  
    cout<<"Hello World";
    return EXIT_SUCCESS;
}
