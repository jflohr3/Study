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
#include <cstdlib>
#include <iostream>

#include <regex>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc<2) 
  {
    printf("I need at least one elevator position (integer set)\n");
    return EXIT_FAILURE; 
  }
  
  // TODO Move this printout to integer check regex
  printf("================================================================\n");
  printf("you handed me arguments:\n");
  for(int i=1; i<argc;++i)
    printf("arg %d:%s\n", i, argv[i]);
  printf("================================================================\n");
  
  std::regex int_regex("^-?[0-9]+");
  /* Param check
   * Expect only inputs from the integer set
   *
   * Sol: Create a regex for the integer number set,
   *  check each input string, fail on any non-integer
   */
  for(int i=1; i<argc; ++i)
  {
    if(!(std::regex_match(argv[i], int_regex)))
    {
      cout << "I only accept integer values with pos or neg prefix\n";
      cout << "\"" << argv[i] << "\"" << " is not an integer\n";
    }
  }
   
   
  
  
  
  
  
  
    cout<<"Hello World";
    return EXIT_SUCCESS;
}
