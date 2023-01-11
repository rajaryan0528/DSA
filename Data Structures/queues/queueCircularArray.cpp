/* 
  -->Implement Queue  using Circular Array representation
  -->% operator reresents the number of cycles traversed 
*/
/*
 -->An array is called circular if we consider the first element as next of the last element.
 -->This queue will act as a circular queue
 */

#include <iostream>
using namespace std;
class queue
{
private:
    int rear,front,size;
    int *items;

public:
    queue(int n)
    {
        items=new int[n];
        size=n;
        rear = -1;
        front = -1;
    };
    ~queue(){};
    void dequeue();
    void enqueue(int);
    void disp();
    bool isEmpty();
};

void queue::disp()
{
    if (rear == -1 && front == -1)
    {
        cout << "Empty Queue" << endl;
    }
    else if(front<=rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    //we have  already traversed the queue once
    else{
        for (int i = front;i<=size-1 ; i++)
        {
            cout << items[i] << " ";
        }

        for(int j=0;j<=rear;j++)
        {
            cout <<items[j]<<" ";
        }
        cout<<endl;    
    }
}

void queue::dequeue()
{
    if (rear == -1 && front == -1)
    {
        cout << "Underflow" << endl;
        return;
    }
    //single element
    else if (front==rear)
    {
        cout<<items[front]<<endl;
        front=rear=-1;
    }

    else
    {
        cout<<items[front]<<endl;
        front=(front+1)%size;

    }
}

void queue::enqueue(int e)
{
    if ((rear+1%size)==front )
        cout << "Overflow" << endl;

    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        items[rear] = e;
    }

    else
    {

        rear=(rear+1)%size;
        items[rear] = e;
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
    int n;
    cout<<"Enter the queue size : ";
    cin>>n;
    queue q(n);
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
            q.dequeue();

        case 3:
            q.disp();
        }

    } while (ch != 0);

    return 0;
}
