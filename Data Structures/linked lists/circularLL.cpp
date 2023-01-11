/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the circularly linked list
(ii) Insert an element x at the end of the circularly linked list
(iii) Insert an element x at i th  position in the circularly linked list
(iv) Remove an element from the beginning of the circularly linked list
(iv) Remove an element from the end of the circularly linked list
(v) Remove an element from  i th  position in the circularly linked list.
(vi) Search for an element x in the circularly linked list and return its pointer
(vii) Concatenate two circularly linked lists , also overload +
(vii)Reverse a  doubly linked list
*/

#include <iostream>
using namespace std;

class node
{
public:
    node(){};
    node(int v)
    {
        data = v;
        next = NULL;
    }

    ~node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next == NULL;
        }
    }
    int data;
    node *next;
};

class cll
{
    node *temp = NULL;
    node *last = NULL;
    node *iter = NULL;

public:
    cll(){};
    ~cll(){};
    void display();
    int count();
    void add_to_head(int v);
    void add_to_tail(int);
    void add_at_loc(int i, int e);
    void del_from_head();
    void del_from_tail();
    void del_from_loc(int i);
    int search(int);
    void concatenate(cll &ob);
    void operator+(cll &ob);
    void reverse();
};

void cll::display()
{
    
    temp=last;
    do{
        cout << temp->data << "->";
        temp = temp->next;
    }
    while(last!=temp);
    cout << "NULL" << endl;
}

int cll::count()
{

    int count=0;
    if (last->next = last)
    {
         count =1;
    }
    else{
    temp = last;
    do
    {
        temp = temp->next;
        count++;
    } while (last != temp);
    }
    return count;
}

void cll::add_to_head(int v)
{
    temp = new node(v);
    if (last == NULL)
    {
        last = temp;
        last->next =last;   //pointing to itself , the first node 
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
    }
}

void cll::add_to_tail(int v)
{
    temp = new node(v);
    if (last == NULL)
    {
        last = temp;
        last->next = last; // pointing to itself , the first node
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void cll::add_at_loc(int i, int e)
{
    // i is position
    // add an element after the ith position
    temp = new node(e);
    // temp->data = e;
    // temp->next = NULL;
    iter =last;
    if (i == 1)
        this->add_to_head(e);

    else if (i == (this->count()))
    {
        this->add_to_tail(e);
    }

    else
    {
        int count = 0;
        iter =last;
        while (count < (i - 1))
        {

            iter = iter->next; // node at i-1
            count += 1;
        }
        temp->next = iter->next;
        iter->next = temp;
    }
}

void cll::del_from_head()
{
    temp = new node();
    if (last == NULL)
    {
        cout << "List is empty. Cannot delete:)" << endl;
    }
    
    // else if(last->next=last)    //only one node 
    // {
    //     last->next=NULL;
    //     delete last;
    // }
    
    else
    {
        temp =last->next;
        last->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}

void cll::del_from_tail()
{
    temp = new node();
    node *current = NULL;


    if (last == NULL)
    {
        cout << "List is empty. Cannot delete:)" << endl;
    }

    else
    {

        temp =last->next;
        do
        {
            current = temp; // storing the previous node
            temp = temp->next;
        } while (last != temp);
           

        // temp is storing the last node here
        current->next =temp->next; // becomes the last node
        last=current;
        temp->next=NULL;
        delete temp;
    }
}

void cll::del_from_loc(int i)
{
    // i is position
    // delete the  element at the i th position
    temp = new node();
    iter =last;
    if (i == 1)
        this->del_from_head();

    else if (i == (this->count()))
        this->del_from_tail();

    else
    {
        int count = 0;
        iter = last->next;  //from first position 
        while (count <(i-1))
        {
          
            temp = iter; // previous node
            iter = iter->next;
            count += 1;
        }   
        temp->next = iter->next; // point to the address of the node after the deleted node
        iter->next=NULL;
        delete iter;
    }
}

int cll::search(int)
{
    return 0;
}

void cll::concatenate(cll &ob)
{
}

void cll::operator+(cll &ob)
{
}

void cll::reverse()
{
    
}

int main()
{
    cll l;
    l.add_to_tail(2);
    l.add_to_tail(3);
    l.add_to_tail(4);
    l.display();

    return 0;
}
