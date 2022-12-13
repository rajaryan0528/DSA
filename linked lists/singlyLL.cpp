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
    node(){};
    node(int v)
    {
        data = v;
        next = NULL;
    }

    ~node(){
        if (this->next !=NULL)
        {
            delete next;
            this->next ==NULL;
        }
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
    int search(int);
    void concatenate(sll &ob);
    void operator+(sll &ob);
    void reverse();
};

void sll::concatenate(sll &ob)
{
    if (this->first && ob.first == NULL)
        cout << "Both the lists are empty :)" << endl;

    else
    {
        temp = ob.first;
        while (temp != NULL)
        {
            this->add_to_tail(temp->data);
            temp=temp->next;
        }
    }
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

// have to return a pointer to the element not its position
int sll::search(int e)
{
    temp = first;
    int count = 1;
    while (temp->data != e)
    {
        temp = temp->next;
        count += 1;
    }
    cout<<temp<<endl;
    return count;
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

void sll::add_to_tail(int v)
{

    temp = new node(v);
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
    temp = new node(v);
    // temp->data = v;
    // temp->next = NULL;
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
    // add an element after the ith position
    temp = new node(e);
    // temp->data = e;
    // temp->next = NULL;
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
        while (count < (i-1))
        {

            iter = iter->next;    //node at i-1
            count += 1;
        }
        temp->next = iter->next;
        iter->next= temp;
    }
}

void menu()
{
    cout << "----------------*****************--------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Insert an element  at the beginning" << endl;
    cout << "2.Insert an element at the end" << endl;
    cout << "3.Insert an element at i th  position" << endl;
    cout << "4.Delete  an element from the beginning" << endl;
    cout << "5.Delete an element from the end" << endl;
    cout << "6.Delete an element from  i th  position" << endl;
    cout << "7.Search for an element : pointer to the element is returned" << endl;
    cout << "8.Concatenate two singly linked lists , also overload +" << endl;
    cout << "9.Reverse" << endl;
    cout << "10.Display"<<endl;
    cout << "--------------------****************-------------------------------------" << endl;
    cout << "Enter your choice :" << endl;
}

int main()
{
    sll l1, l2,l3;
    int ch;
    int x;
    int i;
    l2.add_to_tail(3);
    l2.add_to_tail(6);
    l2.add_to_tail(7);

    do
    {
        menu();
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exiting :)...." << endl;
            break;

        case 1:
            cout << "Enter the element :";
            cin >> x;
            l1.add_to_head(x);
            break;

        case 2:
            cout << "Enter the element :";
            cin >> x;
            l1.add_to_tail(x);
            break;

        case 3:
            cout << "Enter the element :";
            cin >> x;
            cout << "Enter the poistion to be inserted at :";
            cin >> i;
            l1.add_at_loc(i, x);
            break;

        case 4:
            l1.del_from_head();
            break;

        case 5:
            l1.del_from_tail();
            break;

        case 6:
            cout << "Enter the poistion to be deleted from :";
            cin >> i;
            l1.del_from_loc(i);
            break;

        case 7:
            cout << "Enter the element to be search for:";
            cin >> x;
            cout<<"Element present at :"<<l1.search(x)<<endl;
            break;

        case 8:
            cout<<"Concatenating two lists"<<endl;
            l3+l1;
            l3+l2;
            l3.display();
            break;

        case 9:
            l1.reverse();
            break;

        case 10:
           l1.display();
           break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (ch != 0);
    return 0;
}