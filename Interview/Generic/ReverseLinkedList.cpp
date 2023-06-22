/*
 * Reverse a linked list in order
 * could invert the data in the list (costly for large data)
 * could alter the references (most portable)
 */
#include <cstdlib>
#include <cstdint>

class Data
{
public:
  uint64_t uuid;
  Data* prev;
  Data* next;
};

/* LL data is just a uuid so a uuid list */
class LinkedList
{
public:
  Data* head = nullptr;
  Data* tail = nullptr;
  
  void add(uint64_t new_uuid)
  {
    Data* newData = new Data;
    newData->uuid = new_uuid; // bad name, could be mis-read easily
    newData->next = nullptr;
    newData->prev = nullptr;

    if (head == nullptr) //if head is empty then the data will be assigned to head
    {
        head = newData;
    }
    else
    {
        Data* curr = head;
        while(curr->next != nullptr) // Move the pointer to the last node
        {
            curr = curr->next;
        }
        curr->next = newData; // second to last node's next points to new entry
        newData->prev = curr; // second to last node ptr recorded in this new entry
    }
  }
};

int main(int argc, char* argv[])
{
  return EXIT_SUCCESS;
}
