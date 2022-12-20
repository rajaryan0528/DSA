// Create and perform different operations on Double-ended Queues using Linked List implementation.
/* -->Implementing a queue using linked representation
   -->Single Linked List was used
*/
#include <iostream>
using namespace std;
#define QUEUESIZE 100
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

class queue
{

    node *temp = NULL;
    node *last = NULL;
    node *first=NULL;

    // R E P/E   rear end push()/enqueue()
public:
    int rear = -1;
    int front = -1;
    queue(){};
    ~queue(){};
    void enqueueFront(int);
    void enqueueRear(int);
    void dequeueFront();
    void dequeueRear();
    void display();
};

void queue::enqueueFront(int v)
{

    temp = new node(v);
    if (rear == -1 && front == -1)
    {
        cout<<"Front end is full.Can't add elements from the front."<<endl;
    }

    else
    {
        temp->next =first;
        first = temp;
        --front;
    }
}

void queue::enqueueRear(int v)
{

    temp = new node(v);
    if (rear == -1)
    {
        first=last= temp;
        ++rear;
    }

    else
    {
        if(rear<QUEUESIZE-1)
        {
            last->next = temp;
            last =last->next;
            ++rear;
        }
    }
}



void queue::display()
{
    temp=last;
    cout<<temp->data;
    while (temp->next !=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void queue::dequeueRear()
{
    if(rear !=-1)
    {
       node *prev=NULL;
       temp=first;
       while (temp->next != NULL)
        {
          prev=temp;
          temp = temp->next;}
        prev->next=NULL;
        last=prev;
        delete temp;
        --rear;
    }
    else
       cout<<"Queue is empty."<<endl;
}

void queue::dequeueFront()
{
    if (front == -1)
    {
        cout << "QUEUE is empty.Underflow:)" << endl;
    }
    else
    {
        temp = first;
        first = first->next;
        delete temp;
        ++front;
    }
}

int main()
{
    queue q;
    q.enqueueRear(1);
    q.enqueueRear(2);
    q.enqueueRear(3);
    //q.enqueueFront(3); //not possible
    q.display();
    //q.dequeueFront();
    return 0;
}
