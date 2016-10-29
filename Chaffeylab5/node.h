#ifndef NODE
#define NODE

#include<iostream>
using namespace std;



template<typename Item_Type>

struct node
{
    node(const Item_Type& item);
    node();
    node(node* Next);
    node(node<Item_Type>* Next,Item_Type Item );
    ~node();


    Item_Type item;
    node<Item_Type>* next;

     template <typename T>
    friend ostream& operator << (ostream& outs, const node<T>& printMe);

};
template<typename Item_Type>
node<Item_Type>::node()
{
    item=NULL;
    next=NULL;
}
template<typename Item_Type>
node<Item_Type>::node(const Item_Type& Item)
{
    item=Item;
    next=NULL;//nullptr;
}
template<typename Item_Type>
node<Item_Type>::node(node<Item_Type>* Next)
{
    item=NULL;
    next=Next;
}
template<typename Item_Type>
node<Item_Type>::node(node<Item_Type>* Next,Item_Type Item )
{
    item=Item;
    next=Next;
}
//--------destructor--------
template<typename Item_Type>
node<Item_Type>::~node<Item_Type>()
{

}
//=============operator===============
template<typename T>
ostream& operator << (ostream& outs, const node<T>& printMe)
{
        outs<< printMe.item;
        return outs;
}


#endif // NODE

