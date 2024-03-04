#ifndef LISTASE_H_INCLUDED
#define LISTASE_H_INCLUDED
#define TAM 10
struct INFO
{
    int num;
    char word[TAM];
};
struct NodoListaSE
{
    INFO info;
    NodoListaSE *sgte;
};

// PRIMITIVAS PARA INSERTAR NODOS

void NodoInsertarFinal(NodoListaSE *&lista, INFO dato);
void NodoInsertarPrincipio(NodoListaSE *&lista, INFO dato);
void NodoInsertaranterior(NodoListaSE *&lista, int dato1, INFO dato3);

//PRIMITIVAS PARA BORRAR NODOS

void BorrarUltimoNodo(NodoListaSE *&lista);
void BorrarPrimerNodo(NodoListaSE *&lista);
void BorrarNodoEspecifico(NodoListaSE *&lista, int dato);

//PRIMITIVAS BUSQUEDA Y RECORRIDO DE NODOS

NodoListaSE *ObtenerUltimo(NodoListaSE *lista);
NodoListaSE *BuscarNodoPorEntero(NodoListaSE *lista, int num);
NodoListaSE *BuscarNodoPorChar(NodoListaSE *lista, char word[]);

//PRIMITIVA MOSTRAR LISTA

void ListaMostrar(NodoListaSE *lista);

#endif
