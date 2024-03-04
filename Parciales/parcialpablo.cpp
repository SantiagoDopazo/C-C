#include <iostream>

using namespace std;

typedef struct
{
    int nro_encomienda;
    float peso;
    char vec_destino[200];
    char vec_barrio[50];
    char vec_nombre[50];
    int fecha;//AAAAMMDD
    bool entregado;
}Encomienda;

void borraimpares(int vec[], int tam)
{
    int i=0;
    for(i=0;i<tam;i++)
    {
        if(vec[i]%2)
        {
            vec[i]=vec[i]*2;
        }
    }
}

void Entrega(Encomienda Pedido[], int tam, int fecha)
{
    int i=0;
    for(i=0;i<tam;i++)
    {
        if(Pedido[i].fecha < fecha)
        {
            Pedido[i].entregado=true;
        }
    }
}

int main()
{
    int vec[4] = {1, 2 ,4, 3};
    int i=0, fecha=0, tam=0;
    Encomienda Pedido[4] {
        {1, 500, "Comprador1","pepe","pepe",20020522, false},
        {2, 150, "Comprador1","jose","jose",20051030, false},
        {3, 400, "Comprador1","roberto","jose",20201215, false},
        {4, 100, "Comprador1","jack","jack",20031219 ,false}
    };

    Entrega(Pedido, 4, 20201214);
    borraimpares(vec, 5);
    for(i=0;i<4;i++)
    {
        cout << vec[i] << endl;
    }
    for(i=0;i<4;i++)
    {
        cout<< "esta en " << Pedido[i].entregado << endl;
    }
    

    return 0;
}

