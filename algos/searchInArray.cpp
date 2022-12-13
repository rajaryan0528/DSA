/*
Given a list of N elements, which follows no particular arrangement, you are required to search an
element x in the list. The list is stored using array data structure. If the search is successful, the output
should be the index at which the element occurs, otherwise returns -1 to indicate that the element is
not present in the list. Assume that the elements of the list are all distinct. Write a program to perform
the desired task

Given a list of N elements, which is sorted in ascending order, you are required to search an element x
in the list. The list is stored using array data structure. If the search is successful, the output should be
the index at which the element occurs, otherwise returns -1 to indicate that the element is not present
in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired
task.
*/

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
int linearSearch(int *&a, int n, int x)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
            pos = i + 1;
    }
    return pos;
}

int binarySearch(int *&a, int n, int x)
{
    bubbleSort(a, n);
    int low = 0;
    int high = n - 1;
    int mid = 0;
    int pos = -1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x == a[mid])
            pos = mid + 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return pos;
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

    int x;
    cout << "Enter the element to search for : ";
    cin >> x;
    int pos;
    pos = linearSearch(list, n, x);
    if (pos == -1)
        cout << "Element not found." << endl;
    else
        cout << "Found " << x << " at position --> " << pos << endl;
    return 0;

    cout << "Enter the element to search for : ";
    cin >> x;
    pos = binarySearch(list, n, x);
    if (pos == -1)
        cout << "Element not found." << endl;
    else
        cout << "Found " << x << " at position --> " << pos << endl;
    return 0;
}