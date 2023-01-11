//WAP to implement Symmetric Matrix using one - dimensional array
#include <iostream>
using namespace std;

class symmetric
{

private:
    int n;
    int *arr;

public:
    symmetric(int N)
    {
        n = N;
        arr = new int[(n *n + n) / 2];
    }
    ~symmetric() { delete[] arr; }
    int retrieve(int i, int j);
    void store(int i, int j, int x);
    void display();
};

int symmetric::retrieve(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > n)
    {
        cout << "Out of Bounds";
        return -1;
    }
    if (i < j)
    {

        int temp = i;
        i = j;
        j = temp;
    }
    return arr[i * (i - 1) / 2 + j - 1];
}

void symmetric::store(int i, int j, int x)
{
    int k = 0;
    if (i < 1 || j < 1 || i > n || j > n)
    {
        cout << "Out of Bounds";
        return;
    }
    k = (i * (i - 1) / 2 + j - 1);   //for the linear array
    cout << "Array index pos : " << k << endl;
    arr[k] = x;
}

void symmetric::display()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i < j)
                cout << arr[j * (j - 1) / 2 + i - 1] << "\t";
            else
                cout << arr[i * (i - 1) / 2 + j - 1] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter no of rows & columns : ";
    cin >> n;
    symmetric s1(n);
    int i, j, y;
    cout << "Enter  the lower triangular elements of STM : \n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
        {
            cin >> y;
            s1.store(i, j, y);
        }
    cout << "The symmetric Triangular matrix is :\n";
    s1.display();
    cout << "Enter the location for retrival :";
    cin >> i >> j;
    cout << "\nRetrieved value is : " << s1.retrieve(i, j);
    return 0;
}