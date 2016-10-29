#ifndef QUEUELIST
#define QUEUELIST

#include "node.h"

#include<iomanip>
#include<iostream>
#include"linkedlist.h"
using namespace std;
template<typename Item_Type >
class Queue
{
public:
    //--------list functions----------------
    ~Queue();
    Queue();
    Queue(const Queue& r);
    bool isnotempty();
    void Push(const Item_Type &item);
    Item_Type pop();
    Queue (Item_Type& This);
    void printlist();
    void clearlist();
    Item_Type front();
    void operator = (const Queue<Item_Type>& RHS);
    template<typename T>
    friend ostream& operator << (ostream& outs, const Queue<T>& printMe);
private:
    node<Item_Type>* Front;
    node<Item_Type>* Back;

};
template<typename Item_Type >
Queue<Item_Type>::Queue(const Queue& r)
{
    Front= CopyList(r.Front);
    Back=EndofList(r.Front);

}
template<typename Item_Type >
Item_Type Queue<Item_Type>::front()
{
   return(Front->item);
}
template<typename Item_Type >
Item_Type Queue<Item_Type>:: pop()
{
    Item_Type temp = Front->item;
    Delete_Node(Front,Front);
    return(temp);
}
template<typename Item_Type >
Queue<Item_Type>::~Queue<Item_Type>()
{
    ClearList(Front);
    Back=NULL;
}
template<typename Item_Type >
Queue<Item_Type>::Queue()
{
    Front=NULL;
    Back=NULL;

}
template<typename Item_Type >
void Queue<Item_Type>::Push (const Item_Type &item)
{
    cout<<endl<<"inside queue push"<<endl<<endl;
    if(Front==NULL)
    {
        cout<<"inside queue push if"<<endl;

        InsertHead(Front,item);
        cout<<"inside queue push after inserthead"<<endl;
        Back=Front;
    }
    else
    {
        cout<<"else push"<<endl;
        Back=Insert_After(Front,item,Back);

    }
    cout<<"endof queue push"<<endl;
}
template<typename Item_Type >
Queue<Item_Type>:: Queue(Item_Type &This)
{
    InsertHead(Front,This);
    Back=EndofList(Front);
}
template<typename Item_Type >
void Queue<Item_Type>::printlist()
{
    //cout<<"inside Queue Print list"<<endl;
    PrintList(Front);
}
template<typename Item_Type >
void Queue<Item_Type> ::clearlist()
{
    ClearList(Front);
    Back=NULL;
}
template<typename Item_Type >
void  Queue<Item_Type>::operator = (const Queue<Item_Type>& RHS)
{
   Front= CopyList(RHS.Front);
   Back=EndofList(Front);
}
template<typename T>
ostream& operator << (ostream& outs, const Queue<T>& printMe)
{
    cout<<"Queue << "<<endl;
    node<T>*walker =printMe.Front;
    while(walker!=NULL)
    {
        outs<< " "<<walker->item;
        walker=walker->next;

    }
        return outs;
}
template<typename Item_Type >
bool Queue<Item_Type>:: isnotempty()
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

#endif // QUEUELIST

