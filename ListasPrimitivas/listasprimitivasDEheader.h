#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED
#define TAM 10
struct INFO
{
    int num;
    char word[TAM];
};
struct NodoListaDE
{
    INFO info;
    NodoListaDE *sgte;
    NodoListaDE *ant;
};

// PRIMITIVAS PARA INSERTAR NODOS

void NodoInsertarFinal(NodoListaDE *&lista, INFO dato);
void NodoInsertarPrincipio(NodoListaDE *&lista, INFO dato);
void NodoInsertaranterior(NodoListaDE *&lista, int dato1, INFO dato3);

//PRIMITIVAS PARA BORRAR NODOS

void BorrarUltimoNodo(NodoListaDE *&lista);
void BorrarPrimerNodo(NodoListaDE *&lista);
void BorrarNodoEspecifico(NodoListaDE *&lista, int dato);

//PRIMITIVAS BUSQUEDA Y RECORRIDO DE NODOS

NodoListaDE *ObtenerUltimo(NodoListaDE *lista);
NodoListaDE *BuscarNodoPorEntero(NodoListaDE *lista, int num);
NodoListaDE *BuscarNodoPorChar(NodoListaDE *lista, char word[]);

//PRIMITIVA MOSTRAR LISTA

void ListaMostrar(NodoListaDE *lista);

#endif
