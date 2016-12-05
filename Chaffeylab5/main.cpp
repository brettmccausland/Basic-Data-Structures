#include <iostream>
#include <vector>
//#include"Booklist.h"
#include"stacklist.h"
#include"queuelist.h"
#include "list"
void Exercise12_1();//
void Exercise12_3();//
void Exercise12_4();//
void Exercise12_6();//
void Exercise12_9();//
void Exercise12_15();//done
void Exercise12_16();//done

//template<typename T>
void downsize(list<string> &names);
void lprint(list<string>& names);

using namespace std;
int main()
{
  system("clear");

     //Exercise12_15();
    //Exercise12_16();
    Exercise12_1();
  return 0;
}
void Exercise12_1()
{
    list<string> names;
    names.push_back("ron");
     names.push_back("tom");
      names.push_back("greg");
       names.push_back("jeff");
        names.push_back("lexie");
         names.push_back("sparkles");
         downsize(names);
         lprint(names);
}
//template<typename T>
void downsize(list<string>& names)
 {
     for(list<string>::iterator a=names.begin();a!=names.end();a++)
     {
          if(a!=names.end())
          {
             a++;
            names.erase(a);
         }
     }
 }
void lprint(list<string>& names)
 {
     for(list<string>::iterator a=names.begin();a!=names.end();a++)
         cout<<*a<<" ";
 }

void Exercise12_3()
{
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	Node(const string& data) : Data(data) {
	}
	string Data;
};

bool NodeLess(const Node& n1, const Node& n2) {
	return n1.Data < n2.Data;
}

int main() 
{

	std::list<Node> l;
	l.push_back(Node("d"));
	l.push_back(Node("c"));
	l.push_back(Node("a"));
	l.push_back(Node("b"));

	for (auto i = l.begin(); i != l.end(); i++)
	{
		cout << i->Data.c_str() << " ";
	}
	cout << endl;

	l.sort(NodeLess);

	for (auto i = l.begin(); i != l.end(); i++)
	{
		cout << i->Data.c_str() << " ";
	}
	cout << endl;
	
	system("pause");

	return 0;
}
}
void Exercise12_4()
{
  
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
