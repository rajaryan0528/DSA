// WAP to implement Diagonal Matrix using one-dimensional array.
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class diagonalMat
{
    int n;
    int *arr;

public:
    diagonalMat(int N)
    {
        n = N;
        arr = new int[N];
    }
    ~diagonalMat(){ 
        delete[] arr; 
    }
    void store(int i, int j, int x);
    int retrive(int i, int j);
    void show();
};

void diagonalMat::store(int i, int j, int x)
{
    if (i < 1 || j < 1 || i > n || j > n)
    {
        cout << "Out of Bounds";
        return;
    }
    else if (i == j)
        arr[i] = x;

    else
    {
        if (x != 0)
        {
            cout << "x must be zero";
            return;
        }
    }
}

int diagonalMat::retrive(int i, int j)
{
    if (i < 1 || j < 1 || i > n || j > n)
    {
        cout << "Out of Bounds"<< ' ';
        return -1;
    }
    else if (i == j)
        return arr[i];
    else
        return 0;
}

void diagonalMat::show()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                cout << "0\t";
            else
                cout << arr[i] << "\t";
        }
        cout << endl;
    }
}
int main()
{

    int n;
    cout << "Enter  the no. of rows : ";
    cin >> n;

    diagonalMat d1(n);
    int i, j, y;
    cout << "Enter the elements :\n";
    for (i = 1, j = 1; i <= n, j <= n; i++, j++)     //1 based indexing
    { 
        cin >> y;
        d1.store(i, j, y);
    }
    cout << "The diagonal matrix is :\n";
    d1.show();
    cout << "Enter the location of retrival :";
    cin >> i >> j;
    cout << "\nRetrieved value is : " << d1.retrive(i, j);

    return 0;
}
