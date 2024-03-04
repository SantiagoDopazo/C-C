#include <iostream>

using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

void InsertarPrimero (Nodo *&lista, int info);
void InsertarPrincipio (Nodo *&lista, int info);
void MostrarLista (Nodo *lista);
Nodo *ListaConcatenada (Nodo *lista1, Nodo *lista2);
Nodo *ListaIntercalda (Nodo *lista1, Nodo *lista2);

int main()
{
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Nodo *listaConcatenada = NULL;
    Nodo *listaIntercalada = NULL;
    InsertarPrincipio(lista1, 5);
    InsertarPrincipio(lista1, 40);
    InsertarPrincipio(lista1, 80);
    InsertarPrincipio(lista1, 35);

    InsertarPrincipio(lista2, 104);
    InsertarPrincipio(lista2, 150);
    InsertarPrincipio(lista2, 144);
    InsertarPrincipio(lista2, 166);
    InsertarPrincipio(lista2, 177);
    InsertarPrincipio(lista2, 190);

    cout << "Elementos de la lista 1: ";
    MostrarLista(lista1);
    cout << "Elementos de la lista 2: ";
    MostrarLista(lista2);

    listaConcatenada = ListaConcatenada(lista1 , lista2);

    cout << "Elementos de la lista Concatenada: ";
    MostrarLista(listaConcatenada);

    listaIntercalada = ListaIntercalda(lista1 , lista2);

    cout << "Elementos de la lista Intercalada: ";
    MostrarLista(listaIntercalada);

    return 0;
}

void InsertarPrimero (Nodo *&lista, int info)
{
    Nodo *aux = new Nodo();
    aux->info = info;
    aux->sgte = NULL;
    lista = aux;
    return;
}
void InsertarPrincipio (Nodo *&lista, int info) //PUSH
{
    Nodo *aux = new Nodo();
    aux->info = info;
    aux->sgte = lista;
    lista = aux;
    return;
}
void MostrarLista (Nodo *lista)
{
    while(lista != NULL)
    {
        cout << lista->info << " | ";
        lista = lista->sgte;
    }
    cout << endl;
    return;
}
Nodo *ListaConcatenada (Nodo *lista1, Nodo *lista2)
{
    Nodo *lista_concatenada = NULL;
    Nodo *aux = NULL;

    aux=lista1;

    while(aux != NULL)
    {
        InsertarPrincipio(lista_concatenada, aux->info);
        aux=aux->sgte;
    }
    aux = lista2;
    while(aux != NULL)
    {
        InsertarPrincipio(lista_concatenada, aux->info);
        aux=aux->sgte;
    }

    return lista_concatenada;
}
Nodo *ListaIntercalda (Nodo *lista1, Nodo *lista2)
{
    Nodo *lista_intercalada = NULL;

    while(lista1 != NULL && lista2 != NULL)
    {
        InsertarPrincipio(lista_intercalada, lista1->info);
        lista1 = lista1->sgte;
        InsertarPrincipio(lista_intercalada, lista2->info);
        lista2 = lista2->sgte;

    }
    while(lista1 != NULL)
    {
        InsertarPrincipio(lista_intercalada, lista1->info);
        lista1 = lista1->sgte;
    }
    while(lista2 != NULL)
    {
        InsertarPrincipio(lista_intercalada, lista2->info);
        lista2 = lista2->sgte;
    }
    return lista_intercalada;
}