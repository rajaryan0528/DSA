#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void bubbleSort(int *&a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void selectionSort(int *&a,int n){      //select the elemenand placed it at its correct position
    int minIndx=0;
    for(int i=0;i<n;i++)
    {
        minIndx=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[minIndx])
                minIndx=j;
        }
        swap(a[i],a[minIndx]);
    }
}

void insertionSort(int *&a, int n) {     //take an element and put it at its right position in the sub array
    for(int i=1;i<n-1;i++)
    {
        for(int j=i+1;j>0;j--)
        {
            if(a[j]<a[j-1])
               swap(a[j],a[j-1]);
        }
    }
}

void display(int *&a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int *list, n;
    cout << "Enter the number of elements : ";
    cin >> n;
    list = new int[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    insertionSort(list,n);
    display(list, n);
    return 0;
}