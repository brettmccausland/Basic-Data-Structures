#ifndef NODE
#define NODE

class List;
class Iterator;

using namespace std;
class Node
{
public:
   /**
      Constructs a node with a given data value.
      @param s the data to store in this node
   */
   Node(string s);
private:
   string data;
   Node* previous;
   Node* next;
friend class List;
friend class Iterator;
};
#endif // NODE

