#ifndef ITERATOR_H
#define ITERATOR_H
#include "Booknode.h"
#include "Booklist.h"

class Iterator
{
    friend class List;
public:
   Iterator();
   string get() const;
    // Advances the iterator to the next node.
    void next();
    //Moves the iterator to the previous node.
   void previous();
    //Compares two iterators
    // @param b the iterator to compare with this iterator
    //@return true if this iterator and b are equal
   bool equals(Iterator b) const;
private:
   Node* position;
   List* container;

};
Iterator::Iterator()
{
   position = NULL;
   container = NULL;
}

string Iterator::get() const
{
   assert(position != NULL);
   return position->data;
}

void Iterator::next()
{
   assert(position != NULL);
   position = position->next;
}

void Iterator::previous()
{
   assert(position != container->first);
   if (position == NULL)
      position = container->last;
   else
      position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
   return position == b.position;
}
#endif // ITERATOR_H
