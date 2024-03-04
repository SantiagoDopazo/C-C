#include <iostream>
#include <stdio.h>
#include <cstring>
#include "listasprimitivasDEheader.h"

using namespace std;

// PRIMITIVAS PARA INSERTAR NODOS

void NodoInsertarFinal(NodoListaDE *&lista, INFO dato)
{
    NodoListaDE *aux;
    NodoListaDE *nuevo = new NodoListaDE();

    aux = ObtenerUltimo(lista);
    nuevo->info = dato;
    if(aux)
    {
        nuevo->sgte = aux->sgte;
        nuevo->ant = aux;
        aux->sgte = nuevo;
    }
    else
    {
        nuevo->sgte = NULL;
        nuevo->ant = NULL;
        lista = nuevo;
    }
}
void NodoInsertarPrincipio(NodoListaDE *&lista, INFO dato)
{
    NodoListaDE *nuevo = new NodoListaDE();

    nuevo->info = dato;
    if(lista)
    {
        nuevo->sgte = lista;
        nuevo->ant = NULL;
        lista->ant = nuevo;
        lista = nuevo;
    }
    else
    {
        nuevo->sgte = NULL;
        nuevo->ant = NULL;
        lista = nuevo;
    }
    return;
}
void NodoInsertaranterior(NodoListaDE *&lista, int dato1, INFO dato3)
{
    NodoListaDE *aux;
    NodoListaDE *aux2;
    NodoListaDE *nuevo = new NodoListaDE();

    aux = lista;
    if(aux)
    {
        while(aux && aux->info.num != dato1)
        {
            aux2 = aux;
            aux = aux->sgte;
        }
        if(aux && aux2)
        {
            nuevo->info = dato3;
            nuevo->sgte = aux;
            aux->ant = nuevo;
            aux2->sgte = nuevo;
            nuevo->ant = aux2;
        }
        else
        {
            cout << "No se encontraron los Nodos buscados para insertar entre ellos" << endl;
        }
        return;
    }
    else
    {
        cout << "No hay lista cargada todavia" << endl;
        return;
    }
}

//PRIMITIVAS PARA BORRAR NODOS

void BorrarUltimoNodo(NodoListaDE *&lista)
{
    NodoListaDE *aux;
    NodoListaDE *aux2;

    aux = lista;
    aux2 = lista;
    if(aux)
    {
        aux = ObtenerUltimo(lista);
        while(aux2->sgte != aux)
        {
            aux2 = aux2->sgte;
        }
        aux2->sgte = NULL;
        delete aux;
    }
    else
    {
        delete lista;
        cout << "la lista esta vacia" << endl;
    }
    return;
}
void BorrarPrimerNodo(NodoListaDE *&lista)
{
    NodoListaDE *aux;

    aux=lista;
    if(aux)
    {
        lista = lista->sgte;
        lista->ant = NULL;
        delete aux;
    }
    else
    {
        delete lista;
        cout << "La lista esta vacia" << endl;
    }
    return;
}
void BorrarNodoEspecifico(NodoListaDE *&lista, int dato)
{
    NodoListaDE *aux;
    NodoListaDE *aux2;

    aux=lista;
    if(aux)
    {
        while(aux && aux->info.num != dato)
        {
            aux2 = aux;
            aux = aux->sgte;

        }
        if(aux && aux2)
        {

            aux2->sgte = aux->sgte;
            aux->sgte->sgte->ant = aux2;
            delete aux;
        }
        else
        {
            cout<< "El dato a borrar no fue encontrado" << endl;
        }        
    }
    else
    {
        delete lista;
        cout << "La lista esta vacia" << endl;
    }
    return;
}

//PRIMITIVAS BUSQUEDA Y RECORRIDO DE NODOS

NodoListaDE *ObtenerUltimo(NodoListaDE *lista)
{
    if(lista)
    {
       while (lista->sgte)
       {
            lista = lista->sgte;
       }
    }
    return lista;
}
NodoListaDE *BuscarNodoPorEntero(NodoListaDE *lista, int num)
{
    NodoListaDE *aux;

    aux = lista;
    while(aux && aux->info.num != num)
    {
        aux = aux->sgte;
    }
    return aux;
}
NodoListaDE *BuscarNodoPorChar(NodoListaDE *lista, char word[])
{
    NodoListaDE *aux;
    
    aux = lista;
    while(aux && (strcmp(aux->info.word, word)))
    {
        aux = aux->sgte;
    }
    return aux;
}

//PRIMITIVA MOSTRAR LISTA

void ListaMostrar(NodoListaDE *lista)
{
    while(lista)
    {
        cout << "Dato entero: " << lista->info.num << endl;
        cout << "Dato char: " << lista->info.word << endl;
        lista = lista->sgte;
    }
    return;
}

int main()
{
    NodoListaDE *lista = NULL;
    INFO dato, dato1, dato2;

    dato.num = 2;
    strcpy(dato.word, "Hola");
    dato1.num = 5;
    strcpy(dato2.word, "Hpipi");
    dato2.num = 6;
    strcpy(dato2.word, "pepe");

    NodoInsertarFinal(lista, dato);
    NodoInsertarFinal(lista, dato1);
    NodoInsertarFinal(lista, dato2);
    ListaMostrar(lista);
    return 0;

    
}
