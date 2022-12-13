/*Array implementation of a stack*/
#include <iostream>
using namespace std;
#define STACKSIZE 100

class stack
{
private:
    int top = -1;
    int items[STACKSIZE];

public:
    stack()
    {
        top = -1;
    };
    ~stack(){};
    int pop();
    void push(int);
    void peek();
    bool isEmpty();
};

void stack::peek()
{
    cout << "Top -->" << items[top] << endl;
}

bool stack::isEmpty()
{
    if (top == -1)
        return true;

    else
        return false;
}

int stack::pop()
{
    if (this->isEmpty())
    {
        cout << "Underflow.Stack is empty" << endl;
        return 0;
    }

    else
        return (items[top--]);
}

void stack::push(int e)
{
    if (top >= STACKSIZE - 1)
        cout << "Overflow.Stack is full" << endl;

    else
    {

        items[++(top)] = e;
        cout << e << " pushed into stack\n";
    }
}

void menu()
{
    cout << "Stack Operations:" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Push(element) \n2.Pop()" << endl;
    cout << "3.Peek()" << endl;
}

int main()
{
    stack s;
    int ch;
    do
    {
        menu();
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "Exiting Task :)" << endl;

        case 1:
            int e;
            cout << "Enter the element :";
            cin >> e;
            s.push(e);
            break;

        case 2:
            cout << s.pop() << " popped from stack" << endl;

        case 3:
            s.peek();
        }

    } while (ch != 0);

    return 0;
}