// WAP to implement Diagonal Matrix using one-dimensional array.
#include <iostream>
using namespace std;
int main()
{
    // Enter a Diagonal Matrix

    int m = 0, e = 0;
    cout << "Enter the dimension of diagonal matrix : ";
    cin >> m;
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[m];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << "Enter the element : ";
            cin >> e;
            arr[i][j] = e;
        }
        cout << "------------" << endl;
    }

    int i, j, trace[m];
    for (i = 0; i < m; i++)
    {
        trace[i] = arr[i][i]; // copy diagonal elements...
    }
    cout << endl
         << "Trace of the diagonal matrix is :" << endl;
    cout << "[ ";
    for (i = 0; i < m; i++)
    {
        cout << trace[i] << " ";
    }
    cout << "]" << endl;
    cout << endl
         << "Displaying the Original Matrix" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (i == j)
            {
                cout << trace[i] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}