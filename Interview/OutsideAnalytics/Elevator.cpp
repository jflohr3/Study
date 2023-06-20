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
using namespace std;

#include <regex>

  //TODO only use endl 

int main(int argc, char* argv[])
{
  if(argc<2) 
  {
    printf("I need at least one elevator position (integer set)\n");
    return EXIT_FAILURE; 
  }
  
  /* Input numerical constraints
   * Most floors in a building on earth - 154
   * We include negative floors, basements in our solutions
   * Therefore input type must be int16_t
   */
  cout << "Integer inputs must fit inside int_16t" << endl;
  cout << "[2^15-1, 2^15] or [-32,767 , 32,768], inclusive" << endl;
  
  /* Operation numerical constraints
   * Largest floor difference possible given inputs is 2^16
   * This value will be multiplied by 10, so difference container needs types
   *   holding 2^16*10, therefore we use int32_t
   * There is no limit to number of stops so we want the largest unsigned
   *   type to hold the running sum of total travel time uint64_t.
   */
  //TODO check for overflows during running sum
  
  /* Param check
   * Expect only inputs from the integer set
   *
   * Sol: Create a regex for the integer number set,
   *  check each input string, fail on any non-integer
   */
  std::regex int_regex("^-?[0-9]+");
  cout << "Input Arguments:\n";
  cout << "================================================================";
  cout << endl;
  for(int i=1; i<argc; ++i)
  {
    if( !(std::regex_match(argv[i], int_regex)) )
    {
      cout << "I only accept integer values with pos or neg prefix\n";
      cout << "\"" << argv[i] << "\"" << " is not an integer\n";
      cout << "Exiting...\n";
      exit(EXIT_FAILURE);
    }
    else
    {
      cout << "Arg " << i-1 << ": " << argv[i] << endl;
    }
  }
  cout << "================================================================";
  cout << endl;
  
  /*
  vector<int16_t> floor_list;
  vector<int32_t> travel_time_list;
  uint64_t travel_time_sum = 0;
  *
  * We can do the floor_list and travel_time_list in the same container 
  *   to save space.
  */
  vector<int32_t> floor_list;
  vector<int32_t>::iterator floor_list_itr;
  
  // Populate floor list with inputs
  for(int i=1; i<argc; ++i)
  {
    floor_list.push_back( strtol(argv[i], NULL, 10) );
  }
  
  floor_list_itr = floor_list.begin();
  while(floor_list_itr != floor_list.end())
  {
    // This = (this)
    *floor_list_itr = abs(*floor_list_itr - *(floor_list_itr[1])) * 10;
  }
  
  
  
  
  return EXIT_SUCCESS;
}
