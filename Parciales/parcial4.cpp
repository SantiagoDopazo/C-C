#include <iostream>

using namespace std;

typedef struct
{
    int ID_Modelo;
    char vec_Nombre[20];
    float Precio; 
}Modelos;

typedef struct 
{
    int ID_Modelo;
    char vec_Comprador[20];
    int Fecha; //MMDD
}Compras;

void bubblesort(Compras Ventas[],int n)
{
    int i,j =0;
    Compras aux;
    for (i = 0; i < n-1; i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(Ventas[j].ID_Modelo==Ventas[j+1].ID_Modelo)
            {
                if(Ventas[j].Fecha>Ventas[j+1].Fecha)
                {
                    aux=Ventas[j];
                    Ventas[j]=Ventas[j+1];
                    Ventas[j+1]=aux;
                }
            }
        }
    }
    
}

void Imprimir (Modelos Productos[], Compras Ventas[], int n, int f)
{
    int i, j=0;
    for(i=0;i<f;i++)
    {

        cout << "Id_Modelo: " << Productos[i].ID_Modelo << "\tModelo: " << Productos[i].vec_Nombre << "\tPrecio: " << Productos[i].Precio << endl;
        while(Ventas[j].ID_Modelo==Productos[i].ID_Modelo)
        {
            cout << "\tId_Modelo: " << Ventas[j].ID_Modelo << "\tComprador: " << Ventas[j].vec_Comprador << "\tFecha" << Ventas[j].Fecha%100 << "/" << Ventas[j].Fecha/100 << endl;
            j++;
        }

        cout << "\n-------------------------------------------------------------------------\n";

    }
}

int main()
{
    Modelos Productos [4] = {
        {1, "item1", 3000},
        {2, "item2", 5000},
        {3, "item3", 10000},
    };
    Compras Ventas[9] =  {
        {1, "Comprador1", 1022},
        {1, "Comprador2", 1220},
        {2, "Comprador3", 1126},
        {3, "Comprador4", 1201},
        {3, "Comprador5", 1015},
        {3, "Comprador6", 1201}
    };
    int n =6, f = 3; //Cantiad de Ventas son 100 pero para probar mas rapido
    bubblesort(Ventas, n);
    Imprimir(Productos, Ventas, n, f);

    return 0;
}