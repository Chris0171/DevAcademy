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
    int arr[] = {1, 2, 5, 5, 9, 6};

    for (auto i : arr)
    {
        imprimirPar(i);
    }

    return 0;
}
