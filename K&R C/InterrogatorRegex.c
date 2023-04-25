/******************************************************************************
Given a string that can contain only english letters and a regex that may include: 
  1. English letters 
  2. Question marks- a question mark can double the previous letter or can be blank.
For example, str="abbc", reg="ab?c?" is valid


  This question's premise isn't fully detailed.... I'll have to guess.
  Create a naive regex interpreter to find if the supplied string matches
  Only the ? regex special char is to be used. It may allow multiple of the previous
  character or pass on none.

*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// design by parts:
  // for each character idx in input
  // while, regex[currIdx] != '\0', Check regex for match
    // if matched character, store previous char, increment input idx and regex idx
    // if not matched character, is regex character '?', if so then check against 
    //    previous char, if match increment input idx and regex idx 
  // If regex[currIdx == ''\0'], set match to true

int main(int argc, char *argv[])
{
  printf("%d: arguments\n", argc);
  for(int i=0; i<argc; ++i)
    printf("arg %d:%s\n", i, argv[i]);
  printf("\n");
  
  if(argc != 3)
  {
    printf("You must supply two arguments\nInput string, Regex String\nWags finger\n\n");
    return EXIT_FAILURE;
  }
  // argv[1] is input 
  // argc[2] is regex, ? only special char
 
  int in_meta = 0;
  int in_working = 0;
  int regex_i = 0;
  char prev_char = '@'; // set to input char not expected
  while(*(argv[1]+in_meta) != '\0') // for each char in input string
  {
    in_working = in_meta; // start at current toplevel input idx
    while(*(argv[2]+regex_i) != '\0') // for each char in regex
    { // check input string, from current idx in_meta, for regex match
      if(*(argv[1]+in_working) == *(argv[2]+regex_i)) 
      {
        prev_char = *(argv[2]+regex_i); // record this regex char for later use
        ++in_working;
        ++regex_i;
      }
      else if(*(argv[2]+regex_i) == '?') // check for special operator
      { // We have special regex char, check previous regex against current
        if(*(argv[1]+in_working) == prev_char) 
        { // last char matches and current regex char is ?
          ++in_working;
          ++regex_i; // keep prev_char in storage, still valid
        }
      }
      else if(*(argv[1]+in_working) == prev_char) 
      { // last char matches and current regex char is ?
        ++in_working;
        ++regex_i; // keep prev_char in storage, still valid
      }
      else
      { // No direct match and no prev_char special operator match
        break; // stop checking regex against this meta starting idx of input
      }
    }
    // Match check
    if(*(argv[2]+regex_i) == '\0')
    { // Match found
      printf("Found match for regex starting at idx %d\n", in_meta);
      return EXIT_SUCCESS;
    }
    ++in_meta; // increase top-level input string idx
    regex_i = 0; // reset regex idx to beginning
    in_working = 0; // reset input working idx to beginning
    prev_char = '@'; // reset prev char for regex special operator usage
  }
  

  printf("No match found :(\n");
  return EXIT_SUCCESS;
}
