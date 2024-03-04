#include<iostream>

using namespace std;

int findmax(int *p, int n);

int main()
{
    int n, i, max, *ptr_conj;
    cout << "Ingrese la cantidad de valores del conjunto" << endl;
    cin >> n;
    ptr_conj = new int[n];
    for(i=0;i<n;i++)
    {
        cout << "Ingrese el valor "<< i+1<< endl;
        cin >> *(ptr_conj+i);
    }
    max=findmax(ptr_conj,n);
    cout << "El valor maximo es" << max;
    return 0;
    delete [] ptr_conj;
}

int findmax(int *p, int n)
{
    int i, x;

    for(i=1;i<n;i++)
    {
        if(*p<*(p+i))
        {
            *p=*(p+i);
        }
    }
    x=*p;
    return x;
}