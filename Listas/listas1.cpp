#include <iostream>

using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, int ainsertar);
Nodo *ObtenerSiguiente (Nodo *n);
void MayorElemento (Nodo *n);
void PromedioLista (Nodo *n);

int main()
{
    Nodo *lista = NULL;
    int num = 0, flag = 0;

    while(flag != -1)
    {
        cout << "Escriba el numero de la lista que desea agregar, si escribe -1 se terminar el cargado" << endl;
        cin >> num;
        if(num != -1)
        {
            insertarOrdenado(lista, num);
        }
       
    }
    
    MayorElemento (lista);
    PromedioLista (lista);

    return 0;
}

void insertarOrdenado(Nodo *&lista, int ainsertar)
{
    Nodo *paux = lista;
    Nodo *anterior = NULL;
    while (paux && paux->info < ainsertar)
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if (paux!=lista)
    {
        anterior->sgte = new Nodo();
        anterior->sgte->info = ainsertar;
        anterior->sgte->sgte = paux;
    }
    else
    {
        lista= new Nodo();
        lista->sgte = paux;
        lista->info = ainsertar;
    }
    return;
}

Nodo *ObtenerSiguiente (Nodo *n)
{
    if(n!=NULL)
    {
        return n->sgte;
    }
    else
    {
        return NULL;
    }
}

void MayorElemento (Nodo *n)
{
    Nodo *paux=NULL;
    paux=n;

    while(paux != NULL && paux->sgte != NULL)
    {
        paux=ObtenerSiguiente (paux);
    }
    cout << "El mayor Numero es: " << paux->info << endl;

    return;
}

void PromedioLista (Nodo *n)
{
    Nodo *paux=NULL;
    float sum = 0, cont = 0;
    paux=n;

    while(paux != NULL)
    {
        sum += paux->info;
        cont++;
        paux = ObtenerSiguiente(paux);
    }
    cout << "El promedio de la lista es: " << sum/cont << endl;

    return;
}

