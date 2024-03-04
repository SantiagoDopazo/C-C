#include <iostream>
#define JUEGO 5


using namespace std;

int main ()
{
    int k =0,r=0, j=1, aux=0, suma=0, i=0;
    int vec_pares[JUEGO]={0};

    for (i=0;i<JUEGO;i++)
    {
        cout << "Ingrese valores para el juego" << i+1 << endl;

        while(j!=0)
        {
            fflush(stdin);
            cin>> j;
            

            if((j<=10 && j>=-10) && j!=0)
            {
                k++;
            }
            if(j>50)
            {
                suma+=j;
                r++;
            }
            if(j%2==0)
            {
                vec_pares[i]++;
            }
        }
        cout << "La cantida de numeros entre 10 y -10 es: " << k << endl;
        if(r!=0)
        {
            cout << "El promedio de numeros mayores a 50 es: " << suma/r << endl;
        }
        else
        {
            cout << "No hubo numeros mayores de 50" << endl;
        }
        

        k=0;
        suma=0;
        r=0;
        j=1;
    }
    for (i=0;i<JUEGO;i++)
    {
        if(vec_pares[i]>aux)
        {
            aux=vec_pares[i];
            k=i;
        }
    }

    cout << "El Juego con mas numeros pares fue: " << k+1<< endl;
}