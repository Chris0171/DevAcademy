#include <iostream>
#include <string>

using namespace std;

void imprimirPar(int a)
{
    if (a % 2 == 0)
    {
        cout << a << " es par" << endl;
    }
}

int main()
{
    /* int arr[] = {1, 2, 5, 5, 9, 6};

    for (auto i : arr)
    {
        imprimirPar(i);
    } */
   double i = 1.123456789;
   float j = 1.123456789;
   cout.precision(10);
   cout << i << endl;
   cout << j << endl;

    return 0;
}
