#ifndef STACKLIST
#define STACKLIST

#include "iostream"
#include"node.h"
#include "linkedlist.h"

using namespace std;
template<typename Item_Type >
class Stack
{

public:
    Stack();
    Stack (Item_Type& This);
    Stack(const Stack& copyconstruct);
    ~Stack();
    void Push(Item_Type& item);
    Item_Type pop();
    Item_Type top();
    bool isnotempty();
     bool isempty();

    void printlist();
    void clearlist();
    void operator = (const Stack<Item_Type>& RHS);
    template<typename T>
    friend ostream& operator << (ostream& outs, const Stack<T>& printMe);
private:
    node<Item_Type>* Front;

};
template<typename Item_Type >
Stack<Item_Type>::Stack(const Stack& copyconstruct)
{
   Front=CopyList(copyconstruct.Front);
}
template<typename Item_Type >
Item_Type Stack<Item_Type>:: pop()
{
  Item_Type temp;
  temp=Front->item;
  Delete_Node(Front,Front);
  return temp;
}
template<typename Item_Type >
Item_Type Stack<Item_Type>:: top()
{
  return Front->item;
}
template<typename Item_Type >
bool Stack<Item_Type>:: isnotempty()
{
  if (Front==NULL)
  {
      return false;
  }
  else
  {
      return true;
  }
}
template<typename Item_Type >
bool Stack<Item_Type>:: isempty()
{
  if (Front==NULL)
  {
      return true;
  }
  else
  {
      return false;
  }
}
template<typename Item_Type >
Stack<Item_Type>::~Stack<Item_Type>()
{
    ClearList(Front);
}
template<typename Item_Type >
Stack<Item_Type>::Stack()
{
   Front=NULL;
}

template<typename Item_Type >
void Stack<Item_Type>::Push (Item_Type &item)
{
    InsertHead(Front,item);
}
template<typename Item_Type >
Stack<Item_Type>:: Stack(Item_Type& This)
{
    InsertHead(Front,This);
}
template<typename Item_Type >
void Stack<Item_Type>::printlist()
{
     PrintList(Front);
}
template<typename Item_Type >
void Stack<Item_Type> ::clearlist()
{
    ClearList(Front);
}

template<typename Item_Type >
void Stack<Item_Type>::operator = (const Stack<Item_Type>& RHS)
{
    Front=CopyList(RHS.Front);
}
template<typename T>
ostream& operator << (ostream& outs, const Stack<T>& printMe)
{
    node<T>*walker =printMe.Front;
    while(walker!=NULL)
    {
        outs<< " "<<walker->item;
        walker=walker->next;

    }
        return outs;
}

#endif // STACKLIST

