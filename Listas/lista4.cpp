#include <iostream>

using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

int ContarNodos(Nodo *lista);
Nodo *ObtenerUltimo(Nodo *lista);
void InsertarUltimo(Nodo *&lista, int info);
void MostrarLista(Nodo *lista);
void BurbujaLista(Nodo *&lista);

int main (void)
{
    Nodo *lista = NULL;
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        InsertarUltimo(lista, i);
    }

    MostrarLista(lista);

    return 0;
}

void MostrarLista(Nodo *lista)
{
    while(lista != NULL)
    {
        cout << lista->info << " | ";
        lista = lista->sgte;
    }

    cout << endl;
}

Nodo *ObtenerUltimo(Nodo *lista)
{
    if(lista != NULL)
    {
        while(lista->sgte != NULL)
        {
            lista = lista->sgte;
        }
    }
    return lista;
}

void InsertarUltimo(Nodo *&lista, int info)
{
    Nodo *aux = NULL;
    Nodo *nuevo = new Nodo();

    nuevo->info = info;
    nuevo->sgte = NULL;

    if(lista != NULL)
    {
        aux = ObtenerUltimo(lista);
        aux->sgte = nuevo;
    }
    else
    {
        lista = nuevo;
    }

    return;
}

int ContarNodos(Nodo *lista)
{
    int i = 0;
    while (lista != NULL)
    {
        i++;
        lista=lista->sgte;
    }
}

void BurbujaLista(Nodo *&lista)
{
    int cantidad = 0, i = 0, j = 0;
    Nodo *aux;

    aux = lista;

    cantidad = ContarNodos(lista);
    for(i=0;i<=cantidad-2;i++)
    {
        for(j=0;j<=cantidad-2-i;j++)
        [
            if(aux->sgte->info < aux->info)
            {
                lista = aux->sgte;
                
            }
        ]
    }
}