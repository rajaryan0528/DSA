/* -->Implementing a queue using linked representation
   -->Circular  Linked List was used
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
    int data;
    node *next;
};

class queue
{

    node *temp = NULL;
    node *last = NULL;

// R E P/E   rear end push()/enqueue()
public:
    int rear=-1;
    int front=-1;
    queue(){};
    ~queue(){};
    void enqueue(int);
    void dequeue();
    void display();
};

void queue::enqueue(int v)
{

    temp = new node(v);
    if (rear==-1 && front==-1)
    {
        last = temp;
        last->next=last;
        ++rear;
    }

    else
    {
        temp->next = last->next;
        last->next = temp;
        last=temp;
        ++rear;
    }
}

void queue::display()
{
    //when a single node is remains
    //yet to handle that 
    
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=last->next);
}

void queue::dequeue()
{
    int val;
    temp =last->next;
    node *current = NULL;

    if (rear==-1 && front==-1)
    {
        cout << "QUEUE is empty.Underflow:)" << endl;
    }
    else
    {
        temp=last->next;
        if(temp->next==last->next)
        {
           delete temp;
           delete last;
           cout<<"Queue is empty."<<endl;
        }

        else{
              last->next=temp->next;
              delete temp;
              ++front;
        }
    }
}


int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    //q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}

