/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at the end of the singly linked list
(iii) Insert an element x at i th  position in the singly linked list
(iv) Remove an element from the beginning of the singly linked list
(iv) Remove an element from the end of the singly linked list
(v) Remove an element from  i th  position in the singly linked list. 
(vi) Search for an element x in the singly linked list and return its pointer
(vii) Concatenate two singly linked lists
(vii)Reverse a  singly linked list
*/
#include <iostream>
using namespace std;
class node 
{
    public:
      int data;
      node* next;
};

class sll
{
  node *first=NULL;
  node *temp =NULL;
  node *last=NULL;
//   sll()
//   {
//     temp=new node();
//     temp->data=0;
//     temp->next=NULL;
//   }

//   sll(int val)
//   {
//       temp = new node();
//       temp->data = val;
//       temp->next = NULL;
//       head=last=temp;
//   }
public:
  void display(node *n);
  void add_to_head(int v);
  void add_to_tail(int);
  void add_at(int index);
  void del_from_head();
  void del_from_tail();
  void delete_from(int index);
};

void sll::display(node *n)
{
    while(n !=NULL)
    {
        cout<<n->data<<"->";
        n=n->next;
    }
}
void sll::add_to_tail(int v)
{
    temp = new node();
    temp->data = v;
    temp->next = NULL;
    if (first == NULL)
    {
        first = last = temp;
     }

     else{
          last->next=temp;
          last=temp;
     }

    display(first);


}

void sll::add_to_head(int v)
{
    
    temp->data = v;
    temp->next = NULL;
    if (first == NULL)
    {
        first = last = temp;
     }

     else{
          temp->next=first;
          first=temp;
     }

     display(first);
}


int main()
{
   sll list;
   list.add_to_tail(10);
   list.add_to_tail(30);




    // node *head = NULL;
    // node *second = NULL;
    // node *third = NULL;

    // allocate 3 nodes in the heap
    // head = new node();
    // second = new node();
    // third = new node();

    
    // head->data = 1;
    // head->next = second;
    // second->data = 2;
    // second->next = third;

    // third->data = 3;
    // third->next = NULL;



    return 0;
}
