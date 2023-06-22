/*
 * Reverse a linked list in order
 * could invert the data in the list (costly for large data)
 * could alter the references (most portable)
 * 
 * They always say reversing a doubly linked list is easier
 * Maybe if you memorize the solutions like a dweeb
 * I always get trapped trying to reverse them by working outside include
 * Forgetting you only have to switch the prev/next addrs and head/tail addrs
 */
#include <cstdlib>
#include <cstdint>

#include <iostream>
using namespace std;

class Data
{
public:
  uint64_t uuid;
  Data* prev;
  Data* next;
};

/* DoublyLL*/
class DLinkedList
{
public:
  Data* head = nullptr;
  Data* tail = nullptr;
  
  void add(uint64_t in_uuid)
  {
    Data* newData = new Data;
    newData->uuid = in_uuid; // new_uuid bad name, could be mis-read easily
    newData->next = nullptr;
    newData->prev = nullptr;

    if (head == nullptr) //if head is empty then the data will be assigned to head
    {
        head = newData;
        tail = newData;
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
        tail = newData;
    }
  }
  
  void reverse()
  {
    cout << "================================\n";
    cout << "Reversing" << endl;
    cout << "================================\n";


    Data* oldHead = head;
    Data* oldTail = tail;
    Data* currNode = head;
    Data* temp = nullptr;


    // swap object pointers until matching
    while(currNode != nullptr)
    {
      // Just swap next/prev then update head/tail
      temp = currNode->prev;
      currNode->prev = currNode->next;
      currNode->next = temp;
      currNode = currNode->prev;
    }
    
    head = oldTail;
    tail = oldHead;
  }
  
  void print(void)
  {
    cout << "================================\n";
    cout << "Head " << head << endl;
    cout << "Tail " << tail << endl;

    Data* p = head;
    while(p != nullptr)
    {
      cout << p->uuid << " " << endl;
      cout << "this " << p << " " << endl;
      cout << "next " << p->next << " " << endl;
      cout << "prev " << p->prev << " " << endl;

      p = p->next;
    }
    cout << "================================\n";
  }
  
  ~DLinkedList()
  {
    // Gotta free every class Data
    Data* p = head;
    Data* pNext = nullptr;
    while(p != nullptr)
    {
      pNext = p->next;
      delete p;
      p = pNext;
    }
  }
};

/* SinglyLL*/
class SLinkedList
{
public:
  Data* head = nullptr;
  
  void add(uint64_t in_uuid)
  {
    Data* newData = new Data;
    newData->uuid = in_uuid; // new_uuid bad name, could be mis-read easily
    newData->next = nullptr;

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
      curr->next = newData; // last node's next points to new entry
    }
  }
  
  void reverse()
  {
    cout << "================================\n";
    cout << "Reversing" << endl;
    cout << "================================\n";
    
    Data* lastNode = nullptr;
    Data* currNode = head;
    Data* nextNode = nullptr;
    
    while(currNode != nullptr)
    {
      nextNode = currNode->next; 
      currNode->next = lastNode;
      lastNode = currNode;
      currNode = nextNode;
    }
    head = lastNode;
  }
  
  void print(void)
  {
    cout << "================================\n";
    cout << "Head " << head << endl;

    Data* p = head;
    while(p != nullptr)
    {
      cout << "========" << endl;
      cout << p->uuid << " " << endl;
      cout << "this " << p << " " << endl;
      cout << "next " << p->next << " " << endl;
      p = p->next;
    }
    cout << "================================\n";
  }
  
  ~SLinkedList()
  {
    // Gotta free every class Data
    Data* p = head;
    Data* pNext = nullptr;
    while(p != nullptr)
    {
      pNext = p->next;
      delete p;
      p = pNext;
    }
  }
};
  
int main(int argc, char* argv[])
{
  DLinkedList myDList;
  for(int i=0; i<5; ++i)
  {
    myDList.add(i); 
  }
  myDList.print();
  myDList.reverse();
  myDList.print();
  
  SLinkedList mySList;
  for(int i=0; i<4; ++i)
  {
    mySList.add(i); 
  }
  mySList.print();
  mySList.reverse();
  mySList.print();

  /* if we lost a Data object somewhere, the ship leaking brother */
  return EXIT_SUCCESS;
}
