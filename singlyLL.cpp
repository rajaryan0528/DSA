/*Write a program to implement singly linked list which supports the following operations:
(i) Insert an element x at the beginning of the singly linked list
(ii) Insert an element x at the end of the singly linked list
(iii) Insert an element x at i th  position in the singly linked list
(iv) Remove an element from the beginning of the singly linked list
(iv) Remove an element from the end of the singly linked list
(v) Remove an element from  i th  position in the singly linked list.
(vi) Search for an element x in the singly linked list and return its pointer
(vii) Concatenate two singly linked lists , also overload +
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
    node *next;
};

class sll
{
    node *first = NULL;
    node *temp = NULL;
    node *last = NULL;
    node *iter = NULL;

public:
    sll(){};
    ~sll(){};
    void display();
    int count();
    void add_to_head(int v);
    void add_to_tail(int);
    void add_at_loc(int i, int e);
    void del_from_head();
    void del_from_tail();
    void del_from_loc(int i);
    int *search(int);
    void concatenate(sll &ob);
    void operator+(sll &ob);
    void reverse();

};

void sll::concatenate(sll &ob)
{
    if (this->first == NULL && ob.first == NULL)
        cout << "Both the lists are empty :)" << endl;

    else if (this->first == NULL)
        ob.display();

    else if (ob.first == NULL)
        this->display();
    else
    {
        last->next = ob.first; // last node of the first list points to first nodd of the second list
        ob.first = NULL;
        ob.last = NULL;
        this->display();
    }
    return;
}

void sll::operator+(sll &ob)
{
    this->concatenate(ob);
    return;
}

void sll::reverse()
{
    node *before = NULL, *after = NULL;
    temp = first; // current
    while (temp != NULL)
    {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
    first = before; // important
}

// feedback for element  being not  present
int *sll::search(int e)
{
    temp = first;
    int count = 1;
    while (temp->data != e)
    {
        temp = temp->next;
        count += 1;
    }
    cout << "Element present at position :" << count << endl;
}

int sll::count()
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

void sll::display()
{
    node *temp = first;
    if (first == NULL)
        cout << "Empty list. Nothing to show :(" << endl;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
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

    else
    {
        last->next = temp;
        last = temp;
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

    else
    {
        temp->next = first;
        first = temp;
    }
}

void sll::del_from_head()
{
    temp = new node();
    if (first == NULL)
    {
        cout << "List is empty. Cannot delete:)" << endl;
    }

    else
    {
        temp = first;
        first = first->next;
        delete temp;
    }
}

void sll::del_from_tail()
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
        delete temp;
    }
}

void sll::del_from_loc(int i)
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
        int count = 1;
        iter = first;
        while (count < i)
        {

            temp = iter; // previous node
            iter = iter->next;
            count += 1;
        }
        temp->next = iter->next; // point to the address of the node after the deleted node
        delete iter;
    }
}

void sll::add_at_loc(int i, int e)
{
    // i is position
    // add an element agter the ith position
    temp = new node();
    temp->data = e;
    temp->next = NULL;
    iter = first;
    if (i == 1)
        this->add_to_head(e);

    else if (i == (this->count()))
    {
        this->add_to_tail(e);
    }

    else
    {
        int count = 1;
        iter = first;
        while (count < i)
        {

            iter = iter->next;
            count += 1;
        }
        temp->next = iter->next;
        iter->next = temp;
    }
}

int main()
{
    sll l1, l2;
    l1.add_to_tail(10);
    l1.add_to_tail(30);
    l1.add_to_tail(50);
    l1.display();

    l2.add_to_tail(1);
    l2.add_to_tail(3);
    l2.add_to_tail(5);
    l2.display();
    l1+l2;
    l1.concatenate(l2);
    //l1.display();
    //l2.display();
    // list.del_from_loc(3); // i, e
    // list.del_from_tail();
    // list.del_from_head();
    // list.display();
    // list.search(30);
    // list.reverse();

    int ch;

    return 0;
}