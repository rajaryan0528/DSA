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
void selectionSort(){}
void insertionSort(){}
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
    bubbleSort(list,n);
    display(list, n);
    return 0;
}