#ifndef NODE_H
#define NODE_H
#include<istream>
using namespace std;
class Node
{
public:
   Node(string s);
   ~Node();
private:
   string data;
   Node* previous;
   Node* next;
friend class List;
friend class Iterator;
};
Node::Node(string s)
{
   data = s;
   previous = NULL;
   next = NULL;
}

Node::~Node()
{

}
#endif // NODE_H
