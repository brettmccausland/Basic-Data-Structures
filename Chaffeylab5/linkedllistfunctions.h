#ifndef LINKEDLLISTFUNCTIONS
#define LINKEDLLISTFUNCTIONS

#include "nodev4.h"

#include<iomanip>
#include<iostream>
using namespace std;


template<typename Item_Type>
node<Item_Type>* EndofList(node<Item_Type>* head);
template<typename Item_Type>
node<Item_Type>* initialize(Item_Type* Array,int size);
template<typename Item_Type>
node<Item_Type>* SearchList(node<Item_Type> *head, Item_Type key);//Takes a value (key) and returns the pointer to the node containing that item. Null if not found
template<typename Item_Type>
void PrintList(node<Item_Type>*& head);//uses setwPrints the items in list. Uses setw( ) to space the items on the output stream
template<typename Item_Type>
void InsertHead(node<Item_Type> *&head, const Item_Type insertThis);  //Takes a number (insertThis) and inserts it at the head of the list
template<typename Item_Type>
node<Item_Type>* PreviousNode (node<Item_Type>* head,node<Item_Type>* previousToThis); //Takes a pointer to an item in the list (previousToThis) and returns a pointer to the node before the designated node. Returns NULL if the node is the first node in the list.
template<typename Item_Type>
void Insert_Before(node<Item_Type>*& head,Item_Type insertThis,node <Item_Type>* beforeThis); //Takes a value (insertThis), and a pointer to a node in the list (beforeThis) and inserts the value before the designated node.
template<typename Item_Type>
node<Item_Type>* Insert_After(node<Item_Type>*& head,Item_Type insertThis,node<Item_Type> *&afterThis);   //Takes a value (insertThis) and a pointer to a node in the list (afterThis) and inserts the value after the designated node
template<typename Item_Type>
 //Takes a pointer to a node in the list (deleteThis) and removes that node from the list. Deletes the node and returns the item contained within.
void Delete_Node(node<Item_Type> *&head, node<Item_Type>* deleteThis);
template<typename Item_Type>
node<Item_Type>* WhereThisGoes(node<Item_Type> *head, Item_Type Item); //Takes a value (item) and returns a pointer to the node after which the item belongs in the list.  Assumes the list is sorted. Returns NULL if the item belongs at the head of the list.
template<typename Item_Type>
node<Item_Type>* CopyListReverse (node<Item_Type> *head);//Takes a list (head) and returns a pointer to a linked list that is a copy of this list.
template<typename Item_Type>
void ClearList(node <Item_Type>*&head);//Takes a list (head) and deletes all the nodes in the list
template<typename Item_Type>
node<Item_Type>* At (node<Item_Type> *head, Item_Type n);//Takes a position (n) and returns a pointer to the nth position in the list
template<typename Item_Type>
node<Item_Type>* CopyList (node<Item_Type>* head);
template<typename Item_Type>
node<Item_Type>* next_node(node<Item_Type>* head,node<Item_Type>* Next);

//-------------------------------map headers--------------------------------------------------
//template<typename Item_Type,typename Dup>
//void InsertSortedUnique(node<Item_Type>*& head,const Item_Type item,Dup dup);

template<typename Item_Type>
node<Item_Type>* WhereThisGoes(node<Item_Type>* head, Item_Type Item);

//----------map class functions----------------
//---------------------------------------------------------------------------------------------------------
//called by swap keys
//find the position in wherethisgoes which returns its position to insert based on value
//If wherethisgoes doesnt find anything it will return null in which,call inserthead
//else is dup policy of map
//------------------------------------------------------------------------------------------------
//template<typename Item_Type,typename Dup>
//void InsertSortedUnique(node<Item_Type>*& head,const Item_Type item,Dup dup)
//{


//    node<Item_Type>* Find= SearchList(head,item);//make sure the key doesnt exist
//    if(Find!=NULL)
//    {
//        dup(Find->item,item);
//    }
//    //use find to make sure the key doesnt already exist
//    //if exist call dup policy
//    //else do the following
//   else
//   {
//       if(head==NULL)
//       {

//            InsertHead(head,item);
//       }
//       else
//       {

//            node<Item_Type>* temp = WhereThisGoes(head,item);//item.value
//            if(temp==NULL)
//            {
//                InsertHead(head,item);
//            }
//            else
//            {
//                if(temp->item < item)
//                {
//                    Insert_After(head,item,temp);
//                }
//                else
//                {
//                    Insert_Before(head,item,temp);
//                }
//             }
//         }

//        }
//}
//---------------------------------------------------------------------------------------------------------
// called by insert
//find the position in wherethisgoes which returns its position to insert based on key
//If wherethisgoes doesnt find anything it will return the last node in which,call insertafter
//else is dup policy of map
//------------------------------------------------------------------------------------------------

template<typename Item_Type>
node<Item_Type>* WhereThisGoes(node<Item_Type>* head, Item_Type Item)//Takes a value (item) and returns a pointer to the node after which the item belongs in the list.  Assumes the list is sorted. Returns NULL if the item belongs at the head of the list.
{
   node<Item_Type>* walker=head;
   if(walker==NULL)
   {
       return head;
   }
   else
   {
        while((walker!=NULL)&&(walker->item< Item))
        {
          walker=walker->next;
        }
        if((walker!=NULL))
        {
            cout<<walker->item<<endl;
            return walker;
        }
        return PreviousNode(head,walker);
    }

}
//template<typename Item_Type>
//node<Item_Type>* WhereThisGoes(node<Item_Type>* head, Item_Type Item)//Takes a value (item) and returns a pointer to the node after which the item belongs in the list.  Assumes the list is sorted. Returns NULL if the item belongs at the head of the list.
//{
//   node<Item_Type>* walker=head;
//   if(walker==NULL)
//   {
//       return head;
//   }
//   else
//   {
//        while(walker!=NULL)
//        {
//            if(Item<walker->item)
//            {
//                return walker;
//            }
//            else
//            {
//                walker=walker->next;
//            }
//        }
//    cout<<endl;

////    if(head!=PreviousNode(head,walker)){
////        walker=PreviousNode(head,walker);
////    }
//   return walker;
//   }

//}
//template<typename Item_Type>
//node<Item_Type>* WhereThisGoes(node<Item_Type>* head, Item_Type Item)//Takes a value (item) and returns a pointer to the node after which the item belongs in the list.  Assumes the list is sorted. Returns NULL if the item belongs at the head of the list.
//{
//    cout<<"wherethisgoes Beginning"<<endl;
//    node<Item_Type>* walker=head;

//    if(walker!=NULL)
//    {
//         // walker=walker->next;
//         cout<<"where this goes 2"<<endl;
////        if(walker->item< Item)
////        {
////            cout<<" wherethisgoes return head"<<endl;
////            return head;
////        }

//            while((walker->next!=NULL)&&(walker->item< Item)) //while a < b
//            {
//                walker=walker->next;

//             }
//            return walker; // reutns b address to insert after
//            //walker item is always less than the new item??

//     }
//    else
//    {
//        return walker;
//    }

//}

//-----------------------------------LinkListFunctions---------------------------------------
template<typename Item_Type>
void InsertHead(node<Item_Type>*& head, const Item_Type insertThis) //Takes a number (insertThis) and inserts it at the head of the list
{
    cout<<"inside insert head"<<endl;
    // 1.create a new node
    node<Item_Type>* temp = new node<Item_Type>(insertThis);     //next = null
    // 2. temp next points to head
    temp->next=head;
    // 3. head points to where head is pointing
    head=temp;
    cout<<"end of insert head"<<endl;
}
template<typename Item_Type>
void Insert_Before(node<Item_Type>*& head,Item_Type insertThis, node<Item_Type>* beforeThis)//Takes a value (insertThis), and a pointer to a node in the list (beforeThis) and inserts the value before the designated node.
{
    if(head==beforeThis)
    {
        InsertHead(head,insertThis);
    }
    else
    {

    node<Item_Type>* prev;
    node<Item_Type>* ptr= new node<Item_Type> (beforeThis,insertThis);
    prev=PreviousNode(head,beforeThis);
    prev->next=ptr;
    }
}
//test end case
template<typename Item_Type>
node<Item_Type>* Insert_After(node<Item_Type>*& head,Item_Type insertThis,node<Item_Type>*& afterThis)//Takes a value (insertThis) and a pointer to a node in the list (afterThis) and inserts the value after the designated node
{


    node<Item_Type>* ptr= new node<Item_Type>(afterThis->next,insertThis);
    afterThis->next=ptr;
    return ptr;


}
//template<typename k,typename v >
//list<Item_Type> map<K,V>::SwapKeyValues()                        //Returns a List of all the nodes with keys and values swapped.
//{
//  list<k,v> temp;
//}
template<typename Item_Type>
void Delete_Node(node<Item_Type>*& head,node<Item_Type>* deleteThis)//Takes a pointer to a node in the list (deleteThis) and removes that node from the list. Deletes the node and returns the item contained within.
{

        node<Item_Type>* prev=PreviousNode(head,deleteThis);
        if(prev==NULL)
        {

            head=deleteThis->next;
            delete( deleteThis);
        }
        else
        {
        prev->next=deleteThis->next;
        delete(deleteThis);
        }

}
template<typename Item_Type>
void ClearList(node<Item_Type>*& head)//Takes a list (head) and deletes all the nodes in the list
{
    node<Item_Type>* walker =head;
    node<Item_Type>* hold;

    while(walker!=NULL)
    {
        hold=walker->next;
        delete walker;
        walker=hold;
    }
  head=NULL;
}
//------------acsesors-----------------------
template<typename Item_Type>
void PrintList(node<Item_Type>*& head)  //uses setwPrints the items in list. Uses setw( ) to space the items on the output stream
{
    //cout<<"Inside print list"<<endl;
    node<Item_Type>* walker;
    walker=head;

if(walker==NULL)
{
    //cout<<"if in printlist"<<endl;
    cout<<NULL;
}
else
{
   // cout<<"else in print list"<<endl;
 while(walker!=NULL)
 {
     cout<<walker->item<<setw(6);
     walker = walker->next;
 }
}
}
template<typename Item_Type>
node<Item_Type>* SearchList(node<Item_Type>* head,Item_Type key)//Takes a value (key) and returns the pointer to the node containing that item. Null if not found
{
    node<Item_Type>* walker;
    walker=head;
    if(walker==NULL)
    {
        return NULL;
    }
    else
    {
    while((walker!=NULL)&&(walker->item!=key))
    {
        walker=walker->next;
    }
    return(walker);
    }
}
template<typename Item_Type>
node<Item_Type>* PreviousNode(node<Item_Type>* head,node<Item_Type>* previousToThis) //Takes a pointer to an item in the list (previousToThis) and returns a pointer to the node before the designated node. Returns NULL if the node is the first node in the list.
{
 node<Item_Type>* walker= head;
 if(walker==NULL)
 {
     return NULL;
 }
 else
 {
     while((walker!=NULL)&&(walker->next!=previousToThis))
     {
        walker=walker->next;
     }

return(walker);
 }
}

template<typename Item_Type>
node<Item_Type>* CopyListReverse (node<Item_Type>* head)//Takes a list (head) and returns a pointer to a linked list that is a copy of this list.
{
    node<Item_Type>* newhead=NULL;
    node<Item_Type>* walker=head;
    if (walker==NULL)
    {
        newhead=NULL;
        return(newhead);
    }
    else{
    while(walker!=NULL)
    {
        InsertHead(newhead,walker->item);
        walker=walker->next;
    }
    }

    return(newhead);
}
template<typename Item_Type>
node<Item_Type>* CopyList (node<Item_Type>* head)//Takes a list (head) and returns a pointer to a linked list that is a copy of this list.
{
    node<Item_Type>* newhead=NULL;
    node<Item_Type>* walker=head;
    node<Item_Type>* newsave;
    if (walker==NULL)
    {
        newhead=NULL;
        return(newhead);
    }
    else
    {
        InsertHead(newhead,walker->item);
        walker=walker->next;
        newsave=newhead;

        while(walker!=NULL)
        {
            Insert_After(newsave,walker->item,newhead);
            walker=walker->next;
            newhead=newhead->next;
        }
    }

    return(newsave);
}
template<typename Item_Type>
node<Item_Type>* At (node<Item_Type>* head,int n) //should 0 be the head or the first node?( i am makeing choice to make first node 0)
{
    node<Item_Type>* walker = head;
    int i=0;
   while((walker!= NULL)&&(i<n))//nonsense
   {
        walker = walker->next;
        i++;

   }
    return(walker);
}
template<typename Item_Type>
node<Item_Type>* EndofList(node<Item_Type>*head)
{
    node<Item_Type>* walker=head;

    if(walker==NULL)
    {
        return walker;
    }
    else
    {

        while(walker->next!=NULL)
        {
            walker=walker->next;
        }
        return(walker);
    }
}
template<typename Item_Type>
node<Item_Type>* initialize(Item_Type* Array,int size)
{


    node<Item_Type>* newhead=NULL;
    node<Item_Type>* newsave;
    if (size==0)//case empty
    {
       newsave=NULL;
       return(newsave);
    }
    else
    {
        Item_Type* array=(Array+(size-1));//-1 for the off by one (not safe array = empty)
        InsertHead(newhead,*array);//safe
        newsave=newhead;

    for(int i=(size-1);i>0;i--)
    {
        array--;
        Insert_After(newsave,*array,newhead);
        newhead=newhead->next;
    }
    return(newsave);
    }
}
#endif // LINKEDLLISTFUNCTIONS

