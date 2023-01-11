/*
 ->WAP to implement Upper Triangular Matrix using one-dimensional array
   Note:A square matrix is called upper triangular if all the entries above the main diagonal are zero.
*/
#include <iostream>
using namespace std;

class upperTri
{

private:
  int n;
  int *arr;

public:
  upperTri(int N)
  {
    n = N;
    arr = new int[(n*n + n) / 2];
  }
  ~upperTri() { 
    delete[] arr; 
  }

  void store(int i, int j, int x);
  int retrieve(int i, int j);
  void display();
};

void upperTri::store(int i, int j, int x)
{
  int k = 0;
  if (i < 1 || j < 1 || i > n || j > n)
  {
    cout << "Out of Bounds";
    return;
  }
  if (i <= j && x != 0)
  {
    k = (i * (i - 1) / 2 + j - 1);
    arr[k] = x;
  }
  else
    cout << "\nmust be zero";
}

int upperTri::retrieve(int i, int j)
{
  if (i < 1 || j < 1 || i > n || j > n)
  {
    cout << "Out of Bounds";
    return -1;
  }
  if (i > j)
    return 0;
  else
    return arr[i * (i - 1) / 2 + j - 1];
}

void upperTri::display()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i > j)
        cout << "0\t";
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
  upperTri l1(n);
  int i, j, y;
  int bound = (n * n + n) / 2;
  cout << bound;
  int i, j, y;
  for (int x = 0; x < bound; x++) // taking the non zero elements as input
  {
    cout << i << endl;
    cout << "Enter the element, row, column of LTM :\n";
    cin >> y >> i >> j;
    l1.store(i, j, y);
  }
  cout << "The upper Triangular matrix is :\n";
  l1.display();
  cout << "Enter the location for retrival :";
  cin >> i >> j;
  int res = l1.retrieve(i, j);
  cout << "\nRetrieved value is : " << res;

  return 0;
}