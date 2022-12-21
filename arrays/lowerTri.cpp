/*
 ->WAP to implement Lower Triangular Matrix using one-dimensional array
   Note:A square matrix is called lower triangular if all the entries above the main diagonal are zero.
*/
#include <iostream>
using namespace std;

class lowerTri
{

private:
  int n;
  int *arr;

public:
  lowerTri(int N)
  {
    n = N;
    arr = new int[(n * n + n) / 2];    //total number of non zero elements 
  }
  ~lowerTri() { delete[] arr; }
  void display();
  void store(int i, int j, int x);
  int retrieve(int i, int j);
};

void lowerTri::store(int i, int j, int x)
{
  int k = 0;
  if (i < 1 || j < 1 || i > n || j > n)
  {
    cout << "Out of Bounds";
    return;
  }
  if (i >= j && x != 0)     // non zero elements
  {
    k = (i * (i - 1) / 2 + j-1);      //mapping of those non zero element in the array
    arr[k] = x;
  }
  else
    cout << "\nmust be zero";
}

int lowerTri::retrieve(int i, int j)
{
  if (i < 1 || j < 1 || i > n || j > n)
  {
    cout << "Out of Bounds";
    return -1;
  }
  if (i < j)
    return 0;
  else
    return arr[i * (i - 1) / 2 + j - 1];
}

void lowerTri::display()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i < j)
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
  int bound=(n * n + n) / 2;
  cout<<bound;

  lowerTri l1(n);
  int i, j, y;
  for(int x=0;x<bound;x++)        //taking the non zero elements as input 
  {
    cout<<i<<endl;
    cout << "Enter the element, row, column of LTM :\n";
    cin >> y >> i >> j;
    l1.store(i, j, y);
  }

  cout << "The Lower Triangular matrix is :\n";
  l1.display();
  cout << "Enter the location for retrival :";
  cin >> i >> j;
  cout << "\nRetrieved value is : " << l1.retrieve(i, j);
  return 0;
}