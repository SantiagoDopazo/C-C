#include <iostream>
#include <stdio.h>
#include <cstring>
#include "listasprimitivasSEheader.h"

using namespace std;

// PRIMITIVAS PARA MANEJO DE DOS LISTAS

NodoListaSE *UnirListas(NodoListaSE *&lista1, NodoListaSE *&lista2){
    NodoListaSE *aux = NULL;
    if(lista1){
        return lista2;
    }
    if(lista2){
        return lista1;
    }

    aux = ObtenerUltimo(lista1);

    aux = lista2;
}

// PRIMITIVAS ORDENAR LISTAS

void OrdenarLista(NodoListaSE *lista){
    NodoListaSE *aux = NULL;
    int flag = 0;

    if(lista == NULL || lista->sgte == NULL)
    {
        return;
    }
    do{
        aux = lista;
        flag = 0;
        while(aux->sgte)
        {
            if(aux->info.num > aux->sgte->info.num){
                intercambiarInfo(&aux->info, &aux->sgte->info);
                flag = 1;
            }
            aux = aux->sgte;
        }
        
    }while(flag)
}
void intercambiarInfo(INFO *a, INFO *b){
    INFO temp = *a;
    *a=*b;
    *b=temp;
}

// PRIMITIVAS PARA INSERTAR NODOS

void NodoInsertarFinal(NodoListaSE *&lista, INFO dato)
{
    NodoListaSE *aux;
    NodoListaSE *nuevo = new NodoListaSE();

    aux = ObtenerUltimo(lista);
    nuevo->info = dato;
    if(aux)
    {
        nuevo->sgte = aux->sgte;
        aux->sgte = nuevo;
    }
    else
    {
        nuevo->sgte = NULL;
        lista = nuevo;
    }
}
void NodoInsertarPrincipio(NodoListaSE *&lista, INFO dato)
{
    NodoListaSE *nuevo = new NodoListaSE();

    nuevo->info = dato;
    if(lista)
    {
        nuevo->sgte = lista;
        lista = nuevo;
    }
    else
    {
        nuevo->sgte = NULL;
        lista = nuevo;
    }
    return;
}
void NodoInsertaranterior(NodoListaSE *&lista, int dato1, INFO dato3)
{
    NodoListaSE *aux;
    NodoListaSE *aux2;
    NodoListaSE *nuevo = new NodoListaSE();

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
            aux2->sgte = nuevo;
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

void BorrarUltimoNodo(NodoListaSE *&lista)
{
    NodoListaSE *aux;
    NodoListaSE *aux2;

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
void BorrarPrimerNodo(NodoListaSE *&lista)
{
    NodoListaSE *aux;

    aux=lista;
    if(aux)
    {
        lista = lista->sgte;
        delete aux;
    }
    else
    {
        delete lista;
        cout << "La lista esta vacia" << endl;
    }
    return;
}
void BorrarNodoEspecifico(NodoListaSE *&lista, int dato)
{
    NodoListaSE *aux;
    NodoListaSE *aux2;

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

NodoListaSE *ObtenerUltimo(NodoListaSE *lista)
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
NodoListaSE *BuscarNodoPorEntero(NodoListaSE *lista, int num)
{
    NodoListaSE *aux;

    aux = lista;
    while(aux && aux->info.num != num)
    {
        aux = aux->sgte;
    }
    return aux;
}
NodoListaSE *BuscarNodoPorChar(NodoListaSE *lista, char word[])
{
    NodoListaSE *aux;
    
    aux = lista;
    while(aux && (strcmp(aux->info.word, word)))
    {
        aux = aux->sgte;
    }
    return aux;
}

//PRIMITIVA MOSTRAR LISTA

void ListaMostrar(NodoListaSE *lista)
{
    while(lista)
    {
        cout << "Dato entero: " << lista->info.num << endl;
        cout << "Dato char: " << lista->info.word << endl;
        lista = lista->sgte;
    }
    return;
}
