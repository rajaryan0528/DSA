/*1 i. Implement Insertion Sort (The program should report the number of comparisons)
    ii. Implement Merge Sort (The program should report the number of comparisons)
*/

#include <iostream>
using namespace std;
void disp(int *&arr,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void insertionSort(int *&arr,int n)
{
   for(int i=1;i<n;i++)
   { 
     for (int j = i - 1; j > 0; j--)
     {
         if (arr[j] < arr[j - 1])
             swap(arr[j], arr[j - 1]);
     }
     disp(arr,n);
   }
}

void insertionSortRight(int *&arr, int n)  //not working
{
   for (int i = n-1; i > 0; i--)
   {
     for (int j = i-1; j >n-1; j++)
     {
         if (arr[j] > arr[j+1])
             swap(arr[j], arr[j+1]);
     }
     disp(arr, n);
   }
}

int main()
{
    int n;
    int *arr;
    cout<<"Enter the number of elements :";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionSortRight(arr,n);
    cout<<"----------------------"<<endl;
    disp(arr,n);
    return 0;


}