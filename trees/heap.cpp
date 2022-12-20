#include <iostream>
using namespace std;


class heap{
    public:
      heap(){};
      int arr[100];
      int size=0;
      void insert(int val);
      void deleteNode();
      void print();

      
};

void heap::deleteNode(){
    if(size==0){
      cout<<"Nothinh to delete"<<endl;
      return;
    }
    arr[1]=arr[size];
    size--;


    //take root node to its correct position
    int i=1;
    while(i<size)
    {
        int leftIndx=2*i;
        int rightIndx=2*i+1;
        if(leftIndx<size && arr[i]<arr[leftIndx]){
            swap(arr[i],arr[leftIndx]);
            i=leftIndx;
        }
        else if (rightIndx < size && arr[i] < arr[rightIndx])
        {
            swap(arr[i], arr[rightIndx]);
            i = rightIndx;
        }

        else
          return;
    }
}
void heap::insert(int val)
{
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])    //for max heap, change conditions for min heap 
            {
                swap(arr[parent], arr[index]);
                //index = parent;
            }
            else
            {
                return;
            }
        }
}

void heap::print()
{
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " " << endl;
        }
}


int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteNode();
    h.print();

}