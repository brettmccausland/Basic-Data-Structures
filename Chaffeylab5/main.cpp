#include <iostream>
#include <vector>
//#include"Booklist.h"
#include"stacklist.h"
#include"queuelist.h"
void Exercise12_1();//
void Exercise12_3();//
void Exercise12_4();//
void Exercise12_6();//
void Exercise12_9();//
void Exercise12_15();//done
void Exercise12_16();//done
 //void downsize(List<string>& names);
using namespace std;
int main()
{
  system("clear");

     //Exercise12_15();
    Exercise12_16();

  return 0;
}
void Exercise12_1()
{
  //Write a function
  // void downsize(list<string>& names)
  // that removes every second value from a linked list.
}
// void downsize(List<string>& names)
// {
//     for(List::iterator a=names.begin();a!=names.end();a++)
//     {
//         a++;
//         Iterator List::erase(Iterator a);
//     }
// }

void Exercise12_3()
{
  // Write a function sort that sorts the elements of a
  // linked list (without copying them into a vector).
}
void Exercise12_4()
{
  //Write a function merge that merges two lists into one,
  //alternating ele- ments from each list until the end of one
  //of the lists has been reached, then appending the
  //remaining elements of the other list. For example,
  //merging the lists containing A B C and D E F G H
  //should yield the list A D B E C F G H.
}
void Exercise12_6()
{
  // Write a member function
  // List::reverse()
   //that reverses the nodes in a list.
}
void Exercise12_9()
{
  // Write a member function
  // List::get_size()
  // that computes the number of elements in the list,
  // by counting the elements until the end of the list
  // is reached.
}
void Exercise12_15()
{
  //Implement a Stack class, using a linked list of strings. Supply
  //operations size, push, pop, and top, just like in the standard
  //stack template.
    Stack<int> r;
    int a=1;
    int b=a+1;
    int c=9;
    r.Push(a);
    r.Push(b);
    r.Push(c);
    int i =r.top();
    cout<<"top: "<<i<<endl;
    r.pop();
    i=r.top();
    cout<<"top after pop: "<<i<<endl;
}
void Exercise12_16()
{
  //Implement a Queue class, using a linked list of strings.
  //Supply operations size, push, pop, front, and back,
  //just like in the standard stack template.
    Queue<int> myQ;
    int a=1;
    int b=a+1;
    int c=9;
    myQ.Push(a);
    myQ.Push(b);
    myQ.Push(c);
    int i =myQ.front();
    cout<<"top: "<<i<<endl;
    cout<<"my Q: ";
    myQ.printlist();
    cout<<endl;

}
