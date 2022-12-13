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
#include <string>
template <class T> class node
{
public:
    T data;
    node *next;
    node(){};
    node(T v )
    {
          data =v;
          next=NULL;
    }
    
};

template <class T> class sll
{
    node *first;
    node *temp;
    node *last;
    node *iter;

public:
    sll(){
         *first = NULL;
         *temp = NULL;
         *last = NULL;
         *iter = NULL;
    };

    ~sll(){};
    void display();
    int count();
    void add_to_head(T v);
    void add_to_tail(T );
    void add_at_loc(T i, T e);
    void del_from_head();
    void del_from_tail();
    void del_from_loc(int i);
    int *search(T);
    void concatenate(sll &ob);
    void operator+(sll &ob);
    void reverse();
};

// void sll::concatenate(sll &ob)
// {
//     if (this->first == NULL && ob.first == NULL)
//         cout << "Both the lists are empty :)" << endl;

//     else if (this->first == NULL)
//         ob.display();

//     else if (ob.first == NULL)
//         this->display();
//     else
//     {
//         last->next = ob.first; // last node of the first list points to first nodd of the second list
//         ob.first = NULL;
//         ob.last = NULL;
//         this->display();
//     }
//     return;
// }

// template <class T> void sll::operator+(sll &ob)
// {
//     this->concatenate(ob);
//     return;
// }

template <class T> void sll<T>::reverse()
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
// have to return a pointer to the element not its position
// template <class T>  *sll::search(T e)
// {
//     temp = first;
//     int count = 1;
//     while (temp->data != e)
//     {
//         temp = temp->next;
//         count += 1;
//     }
//     cout << "Element present at position :" << count << endl;
// }

template <class T> int sll<T>::count()
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

template <class T> void sll<T>::display()
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

template <class T> void sll<T>::add_to_tail(T v)
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
        last->next = temp;
        last = temp;
    }
}

template <class T> void sll<T>::add_to_head(T v)
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

template <class T> void sll<T>::del_from_head()
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

template <class T> void sll<T>::del_from_tail()
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

template <class T> void sll<T>::del_from_loc(int i)
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

template <class T> void sll<T>::add_at_loc(T i, T e)
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


void dataTypeChoice()
{
    cout << "----------------*****************--------------------------------------" << endl;
    cout << "Please select your preferred data type from the list" << endl;
    cout << "1.Int" << endl;
    cout << "2.Char" << endl;
    cout << "3.Float" << endl;
    cout << "--------------------****************-------------------------------------" << endl;
    cout << "Enter your choice :" << endl;
}

void listOps()
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
    cout << "--------------------****************-------------------------------------" << endl;
    cout << "Enter your choice :" << endl;
}

int main()
{

    int dataT, ch, i;
    string type=" ";

    dataTypeChoice();
    cin>>dataT;
    switch(dataT)
    {
        case 1:
          type="int";
          break;

        case 2:
          type="char";
          break;

        case 3:
           type="double";
           break;

        default:
           type="int";
           break;
    }

    if(type=="int")
    {
      sll<int> l1, l2;
      int x;
    }

    if (type == "char")
    {
        sll<char> l1, l2;
        char x;
    }

    if (type == "double")
    {
        sll<double> l1, l2;
        double x;
    }

    do
    {
        listOps();
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
            l1.display();
            break;

        case 2:
            cout << "Enter the element :";
            cin >> x;
            l1.add_to_tail(x);
            l1.display();
            break;

        case 3:
            cout << "Enter the element :";
            cin >> x;
            cout << "Enter the poistion to be inserted at :";
            cin >> i;
            l1.add_at_loc(i, x);
            l1.display();
            break;

        case 4:
            l1.del_from_head();
            l1.display();
            break;

        case 5:
            l1.del_from_tail();
            l1.display();
            break;

        case 6:
            cout << "Enter the poistion to be deleted from :";
            cin >> i;
            l1.del_from_loc(i);
            l1.display();
            break;

        case 9:
            l1.reverse();
            l1.display();
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (ch != 0);
    return 0;
}