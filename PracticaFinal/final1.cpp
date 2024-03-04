#include <iostream>
#include <stdio.h>
#define CUENTAS 150

using namespace std;

struct NodoSe{
    int num;
    NodoSe *sgt;
};

struct Saldo{
    int numCuenta;
    int cantidadTransacciones;
    int saldo;
}Saldos[150];

struct Transaccion{
    int numCuenta;
    int monto;
};

struct NodoT{
    Transaccion info;
    NodoT *sgte;
};
void intercambiarInfoNodo(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void actualizarSaldos(NodoT *head, Saldo saldos[]){
    int i = 0;
    NodoT *aux = NULL;
    aux = head;
    for(i=0;i<CUENTAS; i++){
        while(aux->sgte && aux->info.numCuenta == saldos[i].numCuenta){
            saldos[i].cantidadTransacciones ++;
            saldos[i].saldo -= aux->info.monto;
            aux=aux->sgte;
        }
    }
};
NodoSe *obtenerUltimo(NodoSe *lista){
    if(lista){
        while(lista->sgt){
            lista = lista->sgt;
        }
    }
    return lista;
}
void intercambiarCuenta(Transaccion *a, Transaccion *b){
    Transaccion temp = *a;
    *a = *b;
    *b = temp;
}
void ordenarListaPorCuenta(NodoT *head){
    NodoT *aux;
    NodoT *aux2;
    aux = head;
    aux2 = head;
    if(!head || !head->sgte){
        return;
    }
    while(aux->sgte){
        aux2 = aux->sgte;
        while(aux2){
            if(aux->info.numCuenta > aux2->info.numCuenta){
                intercambiarCuenta(&aux->info, &aux2->info);
            }
            aux2=aux2->sgte;
        }
        aux = aux->sgte;
    }
}
void fucionarListas(NodoSe *&lista1, NodoSe *&lista2){
    NodoSe *ultimoNodoLista1 = NULL;

    ultimoNodoLista1 = obtenerUltimo(lista1);
   // ultimoNodoLista2 = obtenerUltimo(lista2);

   *ultimoNodoLista1 = *lista2;

}
void ordernarLista(NodoSe *&lista){
    int flag = 0;
    NodoSe *aux = NULL;

    if(lista == NULL || lista->sgt == NULL){
        do
        {
            flag = 0;
            aux = lista;

            while(aux->sgt){
                if(aux->num > aux->sgt->num){
                    intercambiarInfoNodo(&aux->num, &aux->sgt->num);
                    flag = 1;
                }
                aux = aux->sgt;
            }
        } while (flag);
        
    } 
}
void proc(int v[], int len){
    *v=10;
}

/*int main(){
    int *p = NULL;
    int x=30;
    p = new int[3];
    p[1]=x;
    proc(p,3);
    p[2] = *(p+1)+x;
    for(int i =0;i<3;i++)
        cout << *(p+i) << " " << endl;
    delete []p;
    return 0;
}*/

int main(){
    int *p;
    int x =10;
    p = new int [10];
    p[0]=20;
    p[1]=21;
    p[2]=*p;
    p[3]=*(p+1);
    p[4]=*p+*(p+1);
    cout << *(p+4) << endl;
    return 0;
}