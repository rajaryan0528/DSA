/* -->Implementing a stack using linked representation
   -->Singly Linked List was used
*/
#include <iostream>
using namespace std;
#define STACKSIZE 100;
class node
{
public:
    node(){};
    node(int v)
    {
        data = v;
        next = NULL;
    }
    int data;
    node *next;
};

class stack
{

    node *first = NULL;
    node *temp = NULL;
    node *last = NULL;

public:
    int top = -1;
    stack(){};
    ~stack(){};
    int peek();
    void push(int);
    void pop();
    void reverse();
};

void stack::reverse()
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
    first = before; // important step
}

int stack::peek()
{
    cout << endl;
    node *temp = first;
    int count = 0;
    if (top == -1)
        cout << "Empty stack. Nothing to show :(" << endl;

    while (count != top)
    {
        count += 1;
        temp = temp->next;
    }
    return temp->data;
}

void stack::push(int v)
{

    temp = new node(v);
    if (first == NULL)
    {
        first = last = temp;
        ++top;
    }

    else
    {
        last->next = temp;
        last = temp;
        ++top;
    }
}

void stack::pop()
{
    int val;
    temp = new node();
    node *current = NULL;

    if (first == NULL || top == -1)
    {
        cout << "Stack is empty.Underflow:)" << endl;
    }

    if (top == 0)
    {
        cout << first->data << " was popped out." << endl;
        delete first;
        --top;
    }

    else
    {

        temp = first;
        while (temp->next != NULL)
        {
            current = temp; // storing the previous node
            temp = temp->next;
        }

        current->next = NULL; // becomes the last node
        cout << temp->data << " was popped out." << endl;
        delete temp;
        --top;
    }
}

void stackOps()
{
    cout << "----------------   *****************   --------------------------------------" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Push(element)" << endl;
    cout << "2.Pop()" << endl;
    cout << "3.Peek()" << endl;
    cout << "4.Reverse()" << endl;
    cout << "------------------  ****************    -------------------------------------" << endl;
    cout << "Enter your choice :" << endl;
}

int main()
{
    stack s;
    int ch;
    int x;
    int i;
    do
    {
        stackOps();
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exiting :)...." << endl;
            break;

        case 1:
            cout << "Enter the element :";
            cin >> x;
            s.push(x);
            cout << s.top << endl;
            break;

        case 2:
            s.pop();
            cout << s.top << endl;
            break;

        case 3:

            cout << "Top is --> " << s.peek() << endl;
            break;

        case 4:
            s.reverse();

        default:
            cout << "Invalid choice" << endl;
            break;
        }

    } while (ch != 0);
    return 0;
}