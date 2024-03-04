#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Persona{
    char nombreApellido[40];
    char destino[30];
    char vuelo[6];
    int asiento;
    int salida; //ddhhmm
    int llegada; //ddhhmm
};
struct NodoC{
    Persona info;
    NodoC *sgte;
};

void ingresarPasajero(NodoC *&head){
    NodoC *nuevo = new NodoC();
    NodoC *aux = NULL;
    aux=obtenerUltimo(head);

    aux->sgte=nuevo;
    nuevo->sgte=head;
}
NodoC *obtenerUltimo(NodoC *head){
    NodoC *aux = NULL;
    aux = head;
    while(aux->sgte != head){
        aux = aux->sgte;
    }

    return aux;
}
void visualizarPasajero(NodoC *head, char nombre[]){
    NodoC *aux = NULL;
    int flag = 1;
    aux = head;
    do{
        if(!strcmp(aux->info.nombreApellido, nombre)){
            flag = 0;
        }
        aux->sgte;

    }while((aux != head) || flag);

    if(flag){
        cout << "Nombre: " << aux->info.nombreApellido << endl;
        cout << "Destino: " << aux->info.destino << endl;
        cout << "vuelo: " << aux->info.vuelo << endl;
        cout << "asiento: " << aux->info.asiento << endl;  
        cout << "Salida: " << aux->info.salida << endl;
        cout << "Destino: " << aux->info.llegada << endl;                       
    }

    return;    
}
void visualizarLista(NodoC *head){
    NodoC *aux = NULL;
    aux=head;
    do{
        cout << "Nombre: " << aux->info.nombreApellido << endl;
        cout << "Destino: " << aux->info.destino << endl;
        cout << "vuelo: " << aux->info.vuelo << endl;
        cout << "asiento: " << aux->info.asiento << endl;  
        cout << "Salida: " << aux->info.salida << endl;
        cout << "Destino: " << aux->info.llegada << endl; 
        aux=aux->sgte;
    }while(aux->sgte != head);
 
}
void visualizarListaDestino(NodoC *head, char destino[]){
    NodoC *aux = NULL;
    do{
        if(!strcmp(aux->info.destino, destino)){
            cout << "Nombre: " << aux->info.nombreApellido << endl;
            cout << "Destino: " << aux->info.destino << endl;
            cout << "vuelo: " << aux->info.vuelo << endl;
            cout << "asiento: " << aux->info.asiento << endl;  
            cout << "Salida: " << aux->info.salida << endl;
            cout << "Destino: " << aux->info.llegada << endl;
        }
    }while(aux->sgte != head);
}
void eliminarPasajero(NodoC *&head, char nombre[]){
    NodoC *aux = NULL;
    NodoC *aux2 = NULL;
    aux = head;
    while(!strcmp(aux->info.nombreApellido, nombre)){
        if(aux->sgte == head){
            cout << "El nodo con el dato: " << nombre << "no se encuentra" << endl;
            return;
        }
        aux2=aux;
        aux=aux->sgte;
    }
    if(aux->sgte == head && aux2 == NULL){
        delete aux;
        head = NULL;
        return;
    }
    if(aux == head){
        aux2 = head;
        aux2 = head;
    }
}
void modificarDatodPs(NodoC *head, char nombre[]){
    NodoC *aux = NULL;
    int flag = 1;
    do{
        if(!strcmp(aux->info.nombreApellido, nombre)){
            // cout y cin para modificar datos
            return;
        }
        aux=aux->sgte;
    }while(aux!=head);

}

int main(){

return 0;
}