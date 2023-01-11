/*1 i. Implement Insertion Sort (The program should report the number of comparisons)
    ii. Implement Merge Sort (The program should report the number of comparisons)
*/

#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}


int main()
{
  int a=6,b=9;
   swap(a,b);
   cout<<a<<b;
    return 0;
}