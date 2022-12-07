/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the doubly linked list
(ii) Insert an element x at the end of the doubly linked list
(iii) Insert an element x at i th  position in the doubly linked list
(iv) Remove an element from the beginning of the doubly linked list
(iv) Remove an element from the end of the doubly linked list
(v) Remove an element from  i th  position in the doubly linked list.
(vi) Search for an element x in the doubly linked list and return its pointer
(vii) Concatenate two doubly linked lists , also overload +
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
        prev = NULL;
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
    node *prev;
};

class dll
{
    node *first = NULL;
    node *temp = NULL;
    node *last = NULL;
    node *iter = NULL;

public:
    dll(){};
    ~dll(){};
    void display();
    int count();
    void add_to_head(int v);
    void add_to_tail(int);
    void add_at_loc(int i, int e);
    void del_from_head();
    void del_from_tail();
    void del_from_loc(int i);
    int search(int);
    void concatenate(dll &ob);
    void operator+(dll &ob);
    void reverse();
};

void dll::del_from_loc(int i)
{
    // i is position
    // delete the  element at the i th position
    temp = new node();
    iter = first;
    if (i == 1)
        this->del_from_head();

    else if (i == (this->count()))
        this->del_from_tail();

    else
    {
        int count = 0;
        iter = first;
        while (count < (i-1))
        {

            temp = iter; // previous node
            iter = iter->next;
            count += 1;
        }
        iter->prev=NULL;
        temp->next = iter->next; // point to the address of the node after the deleted node
        iter->next->prev=temp;
        iter->next=NULL;
        delete iter;
    }
}

int dll::search(int)
{
    return 0;
}

void dll::concatenate(dll &ob)
{
}

void dll::operator+(dll &ob)
{
}

void dll::reverse()
{
}

void dll::display()
{
    cout << endl;
    node *temp = first;
    if (first == NULL)
        cout << "Empty list. Nothing to show :(" << endl;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int dll::count()
{
    int count = 0;
    node *temp = first;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }

    return count;
}

void dll::add_to_head(int v)
{
    temp = new node(v);
    if (first == NULL)
    {
        first = last = temp;
    }

    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void dll::add_to_tail(int v)
{
    temp = new node(v);
    // empty list
    if (first == NULL)
    {
        first = last = temp;
    }

    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void dll::add_at_loc(int i, int e)
{
    // i is position
    // add an element after the ith position
    temp = new node(e);
    iter = first;
    if (i == 1)
        this->add_to_head(e);

    else if (i == (this->count()))
    {
        this->add_to_tail(e);
    }

    else
    {
        int count = 0;
        iter = first;
        while (count < (i - 1))
        {

            iter = iter->next; // node at i-1
            count += 1;
        }
        temp->next = iter->next;
        iter->next->prev = temp;
        iter->next = temp;
        temp->prev = iter;
    }
}

void dll::del_from_head()
{
    temp = new node();
    if (first == NULL)
    {
        cout << "List is empty. Cannot delete:)" << endl;
    }

    else
    {
        temp = first;
        temp->next->prev = NULL;
        first = temp->next;
        temp->next=NULL;
        delete temp;
    }
}

void dll::del_from_tail()
{
    temp = new node();
    node *current = NULL;

    if (first == NULL)
    {
        cout << "List is empty. Cannot delete:)" << endl;
    }

    else
    {

        temp = first;
        while (temp->next != NULL)
        {
            current = temp; // storing the previous node
            temp = temp->next;
        }

        // temp is storing the last node here
        current->next = NULL; // becomes the last node
        last=temp->prev;
        temp->prev=NULL;
        delete temp;
    }
}

int main()
{
    dll l;
    l.add_to_tail(2);
    l.add_to_tail(5);
    l.add_to_tail(8);
    l.add_to_tail(6);
    l.del_from_loc(1);
    l.del_from_loc(2);
    l.display();
    return 0;
}
