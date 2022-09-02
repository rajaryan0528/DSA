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
      node()
     {
         
     }
      int data;
      node* next;
};

class sll
{
  node *first=NULL;
  node *temp =NULL;
  node *last=NULL;
  node *iter=NULL;

public:
  void display();
  int count();
  void add_to_head(int v);
  void add_to_tail(int);
  void add_at_loc(int i,int e);
  void del_from_head();
  void del_from_tail();
  void delete_from(int index);
};
int sll::count()
{  
    int count=0;
    node *temp=first;
    while(temp !=NULL)
    {
        count+=1;
        temp=temp->next;
    }
    
    return count;
    
}
void sll::display()
{
    node *temp=first;
    while(temp !=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
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
}

void sll::add_to_head(int v)
{
    temp = new node();
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
}

void sll::add_at_loc(int i,int e)
{
    // i is position
    temp = new node();
    temp->data = e;
    temp->next = NULL;
    iter=first;
    if(i==1)
        this->add_to_head(e);

    else if(i==(this->count()))
    {
        cout<<this->count()<<endl;
        this->add_to_tail(e);
    }
        
    else
    {
        int count=0;
        iter=first;
        while(count<i)
        {
           count+=1;
           iter=iter->next;
        }
        temp->next=iter->next;
        iter->next=temp;
        
             
    }
   

}
int main()
{
   sll list;
   list.add_to_head(10);
   list.add_to_head(30);
   list.add_to_head(50);
   list.add_at_loc(2,15);    // i, e
   list.display();
   return 0;
}
