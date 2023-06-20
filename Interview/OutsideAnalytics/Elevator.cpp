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

 Assumptions
• User reads the printout about constraints on the input set. Integers inputs 
    must be in the inclusive range [-2^15-1, 2^15]
• User understands ultimate machine constraints:
  • The input list cannot be of infinite length
  • The simulator cannot handle ultimate travel time sums bigger than
      the machines largest unsigned integer

 Missing Features
• None, besides what normal customers ask for after receiving the completed
    software. I have no crystal ball.
• I'm not providing you with an executable...You didn't mean that in the prompt
*******************************************************************************/
#include <cstdlib>
#include <iostream>
using namespace std;

#include <regex>

void check_inputs(const char* const argv[],
                  const int argc);

void safe_runsum(uint64_t& sum, const int32_t addend);

void print_result(const uint64_t& sum,
                  const char* const argv[],
                  const int argc);

int main(int argc, char* argv[])
{
  check_inputs(argv, argc);
  
  /* We will use this vector for both the floor list and travel time between
   *   floors list
   */
  vector<int32_t> floor_list;
  vector<int32_t>::iterator floor_list_itr;
  
  // Populate floor list with floor index inputs
  for(int i=1; i<argc; ++i)
  {
    floor_list.push_back( strtol(argv[i], NULL, 10) );
  }
  
  // Populate floor list with travel time magnitudes
  floor_list_itr = floor_list.begin();
  while(floor_list_itr != floor_list.end() -1)
  {
    floor_list_itr[0] = abs(floor_list_itr[0] - (floor_list_itr[1])) * 10;
    ++floor_list_itr;
  }
  floor_list.pop_back(); // Remove trailing floor index from travel time vec
  
  uint64_t total_travel_time = 0;
  for(auto& v:floor_list)
  {
    safe_runsum(total_travel_time, v);
  }
 
  print_result(total_travel_time, argv, argc);
  
  return EXIT_SUCCESS;
}

void check_inputs(const char* const argv[],
                  const int argc)
{
  if(argc<3) 
  {
    cout << "I need at least two elevator positions (integer set)" << endl;
    exit(EXIT_FAILURE);
  }
  
  /* Input numerical constraints
   * Most floors in a building on earth - 154
   * We include negative floors, basements in our solution
   * Therefore input type must be int16_t
   */
  cout << "Integer inputs must fit inside int_16t" << endl;
  cout << "[2^15-1, 2^15] or [-32,767 , 32,768], inclusive" << endl << endl;
  
  /* Operation numerical constraints
   * Largest floor difference possible given inputs is 2^16
   * This value will be multiplied by 10, so difference container needs types
   *   holding 2^16*10, therefore we use int32_t
   * There is no limit to number of stops so we want the largest unsigned
   *   type to hold the running sum of total travel time uint64_t.
   */
  
  /* Param check
   * Expect only inputs from the integer set
   *
   * Sol: Create a regex for the integer number set,
   *  check each input string, fail on any non-integer
   */
  std::regex int_regex("^-?[0-9]+");
  for(int i=1; i<argc; ++i)
  {
    if( !(std::regex_match(argv[i], int_regex)) )
    {
      cout << "I only accept integer values, prefix with '-' for negative";
      cout << endl << "\"" << argv[i] << "\"" << " is not an integer" << endl;
      cout << "Exiting..." << endl;
      exit(EXIT_FAILURE);
    }
    else
    {
      // Input relay
      // cout << "Arg " << i-1 << ": " << argv[i] << endl;
    }
  }
}

/*
 * Implementation is quite limited
 *
 * No input checking is provided
 *   sum    : positive 64 bit num unsigned
 *   addend : positive 32 bit num signed
 */
void safe_runsum(uint64_t& sum, const int32_t addend)
{
  if( sum < (UINT64_MAX - addend) )
  {
    sum += addend; 
  }
  else
  {
    cout << "Overflow preempted" << endl;
    cout << "Exiting..." << endl;
    exit(EXIT_FAILURE);
  }
}

void print_result(const uint64_t & sum,
                  const char * const argv[],
                  const int argc)
{
  cout << "================================================================";
  cout << endl;
  cout << "Result:" << endl;
  cout << "Total Travel Time: " << sum << endl;
  cout << "Floors Visited: ";
  for(int i=1; i<argc; ++i)
  {
    if(i==argc-1)
      cout << argv[i] << endl;
    else
      cout << argv[i] << ", ";
  }
  cout << "================================================================";
  cout << endl;
}
