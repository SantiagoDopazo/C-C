#include <iostream>

using namespace std;

void cargadatos(int vec_arr[], int tam)
{
    for(int i=0;i<tam;i++)
    {
        cout << "Ingrese la calificacion: " << i+1 << endl;
        cin >> vec_arr[i];
    }
}
void obtenerestadisticas(int vec_arr[], int tam)
{
    int maximo = 0, minimo = 0, suma=0 , i=0;

    minimo=vec_arr[i];
    for(i=0;i<tam;i++)
    {
        if(vec_arr[i]>maximo)
        {
            maximo=vec_arr[i];
        }
        if(vec_arr[i]<minimo)
        {
            minimo = vec_arr[i];
        }
        suma+=vec_arr[i];
    }

    cout << "La calificacion maxima" << maximo << "La calificacion minima" << minimo << "El promedio" << suma/i <<endl;
    
}
int main()
{
    int vec_arr[30];
    cargadatos(vec_arr, 30);
    obtenerestadisticas(vec_arr, 30);
    
}   