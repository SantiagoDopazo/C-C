#include <iostream>

using namespace std;

int main (void)
{
    int arr[5], i;
    int *p = arr;
    //p=arr;
    cout << "Ingrese 5 numeros" << endl;
    for(i=0;i<5;i++)
    {
        cin >> *(p+i);
    }
    cout << "Usted ingreso:"<< endl;
    for(i=0;i<5;i++)
    {
        cout << *(p+i) << endl;
    }
    return 0;
}