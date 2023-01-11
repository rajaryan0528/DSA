// Implement Queue  using Linear Array representation

#include <iostream>
using namespace std;
#define QUEUESIZE 100

class queue
{
private:
    int rear=-1,front=-1;
    int items[QUEUESIZE];

public:
    queue()
    {
        rear=-1;
        front=-1;
    };
    ~queue(){};
    int dequeue();
    void enqueue(int);
    void disp();
    bool isEmpty();
};

void queue::disp()
{
    if(this->isEmpty())
    {
        cout<<"Empty Queue"<<endl;
    }
    else
    {
       for( int i=front;i<=rear;i++)
      {
        cout<<items[i]<<" ";
      }
      cout<<endl;
    }
}

bool queue::isEmpty()
{
    if (rear==-1 && front==-1)
        return true;

    else
        return false;
}

int queue::dequeue()
{
    if (this->isEmpty())
    {
        cout << "Underflow.Queue is empty" << endl;
        return 0;
    }

    else if(front>rear)
    {
        cout<<"Queue is empty"<<endl;
    }

    else
    {
        return items[front++];
    }
}

void queue::enqueue(int e)
{
    if (rear >= QUEUESIZE - 1)
        cout << "Overflow.Queue is full" << endl;

    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        items[rear]=e;
    }

    else
    {

        items[++(rear)] = e;
        cout << e << " pushed into queue\n";
    }
}

void menu()
{
    cout << "Queue Operations:" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Enqueue(element) \n2.Dequeue()" << endl;
    cout << "3.Disp()" << endl;
}

int main()
{
    queue q;
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
            q.enqueue(e);
            break;

        case 2:
            cout << q.dequeue() << " dequeued." << endl;

        case 3:
            q.disp();
        }

    } while (ch != 0);

    return 0;
}