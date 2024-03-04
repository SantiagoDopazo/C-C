#include <iostream>

using namespace std;

struct encomienda
{
    int Nro_encomienda;
    float peso;
    char destino[100];
    char barrio[50];
    char apellidonombre[50];
    int fecha; //formato AAAAMMDD
    bool entregado;
}Encomiendas[3];

void borrarImpares (int a[], int tam)
{
    int i =0;
    for(i=0; i<tam; i++)
    {
        if(a[i]%2)
        {
            a[i]= a[i]*2;
        }
    }
}
void entregado (encomienda encomiendas[],int tam, int fecha)
{
    for(int i=0; i<tam; i++)
    {
        if(encomiendas[i].fecha < fecha)
        {
            encomiendas[i].entregado = true;
        }
    }
}

int main ()
{
    Encomiendas[0].fecha = 20201204;
    Encomiendas[0].entregado = false;
    Encomiendas[1].fecha = 20211206;
    Encomiendas[1].entregado = false;
    Encomiendas[2].fecha = 20201206;
    Encomiendas[2].entregado = false;

    entregado(Encomiendas, 3, 20201205);

    for (int i = 0; i < 3; i++)
    {
       cout<< Encomiendas[i].fecha << endl << Encomiendas[i].entregado << endl;

    }
    

    return 0;

}