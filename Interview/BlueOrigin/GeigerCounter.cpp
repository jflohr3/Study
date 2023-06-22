/******************************************************************************
 
 Blue Origin initial tech screen question
 
 What I remember:
 * Given a interrupt modeling a radiation event of some kind 
     (variable freq, could be extremely small time between events)
 Program a record keeper for such events
 Such that there is an interface for inquiry of the num of events in the last
   so many milliseconds.

 Bad things I remember:
 
 I used vector.push_front() which doesn't exist.
   It doesn't exist because it is quite the costly operation for the container
   which defeats the purpose of the exercise honestly...

 Purpose:
 Get more comfortable using the vector container as it is meant to be used.
   No operations that utterly circumvent the efficiency of it's backend.
 Explore what we could have gained from using a event_queue to stack the
   incoming events from the interrupt, instead of using a push_back() directly
   on the record container 
   (doubt for this simple ex, but good practice for real-world application)
   well it would allow decoupling of the interrupt handler and the record keeping
   contexts... Though interrupts have no thread context... good to explore this
   see 'https://lwn.net/Articles/302043/'
 Explore other containers for some kind of circular buffer implementation
   some kind has to exist. We want to do this again such that the implementation
   can be left running and not eat all the memory it is allowed until it breaks.
*******************************************************************************/
#include <iostream>
using namespace std;
#include <cstdlib>

int main(int argc, char* argv[])
{
    return EXIT_SUCCESS;
}
