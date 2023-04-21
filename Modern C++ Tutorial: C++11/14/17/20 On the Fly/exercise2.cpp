// Delay C++ exercises since we found multiple firmware, low-level C positions


//TODO alter Mean such that no manual state reset is necessary
//     check type safety and provide assurance for any int width

//TODO find a coding standard YOU prefer. List reasons. Alter code to adhere.
/*
  Yes, I shoud think you might
  She shivered suddenly
  It's like this room of yours, in the middle of a labyrinth of corridors
  just like a dream when you think you will never get out... 
  
  p17 Destination Unknown

*/
#include <iostream>
using namespace std;

class Mean
{
public:
  template<typename T>
  void proc(T num)
  {
    ++numNums;
    runningSum += num;
    mean = (double)runningSum/numNums;
  }
 
  template<typename T, typename... Ts>
  void proc(T num, Ts... nums)
  {
    ++numNums;
    runningSum += num;
    proc(nums...);
  }
  
  void print(void)
  {
    cout << "runningSum: " << runningSum << endl;  
    cout << "numNums: " << numNums << endl;  
    cout << "mean: " << mean << endl;  
  }
  void reset(void)
  {
    runningSum =0;  
    numNums =0;  
    mean =0;  
  }
private:
  int runningSum = 0;
  int numNums = 0;
  double mean = 0.0;
  
};


// TODO allow invocation with a number list, with safety checks.
//    Prove you didn't need to read that one K&R chapter.
int main()
{
  Mean myClass{}; 
  myClass.print();
  
  myClass.proc(1,2,3,4,5,6,7,8,9,10);
  myClass.print();
  myClass.reset();
  
  
  myClass.proc(1l,2.0L,4,4,5ll,6,7ull,8,9ul,10.0f);
  myClass.print();
  myClass.reset();
  
  return(EXIT_SUCCESS);
}