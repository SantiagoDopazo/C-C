#include <iostream>

using namespace std;

void jugar (int x[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        if((x[i]<30 || x[i]%2==0) && (i%2))
            x[i]=x[i]+2;
    }
    return;
}

int main()
{
    int vec[10] = {24, 36, 13, 8, 43, 17, 33};
    jugar(vec, 10);
    for(int i=0;i<10;i++)
        cout << vec[i] << "; ";
    return 0;
}