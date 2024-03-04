#include <iostream>

using namespace std;

struct NodoSE{
    int dato;
    NodoSE *sgte;
};

void interseccionarLista(NodoSE *&lista, NodoSE *&lista2){

}

NodoSE *obtenerUltimo(NodoSE *lista){
    while(lista && lista->sgte){
        lista = lista->sgte;
    }
    return lista;
}

NodoSE *unirListas (NodoSE *&lista, NodoSE *&lista2){
    NodoSE *aux = NULL;
    if(!lista){
        return lista2;
    }
    if(!lista2){
        return lista;
    }
    aux = obtenerUltimo(lista);

    aux->sgte = lista2;

    return lista;
}

void intercambiarDatos(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarLista(NodoSE *lista){
    NodoSE *aux=NULL;
    while(lista){
        aux = lista->sgte;
        while(aux){
            if(lista->dato > aux->sgte->dato){
                intercambiarDatos(&lista->dato, &lista->sgte->dato);
            }
            aux = aux->sgte;
        }
        lista= lista->sgte;
    }
}

struct Reserva{
    int codigoHotel;
    int reservas;
    int diasDisponibles;

}Reservas[50];

struct NodoSE{
    int codigoHotel;
    int diasReservados;
    NodoSE *sgte;
};

void actualizarReservas(Reserva v[], NodoSE *head){

    for(int i =0;i<50;i++){
        while(head && head->codigoHotel == v[i].codigoHotel){
            v[i].reservas ++;
            v[i].diasDisponibles -= head->diasReservados;

            head = head->sgte;
        }
    }
}
struct NodoSEA{
    Almacen info;
    NodoSEA *sgte;
};

struct Almacen{
    long int codigoProducto;
    int peso;
    char tipo;
    long int stock;
};

void NodoInsertarFinal(NodoSEA *&lista, Almacen dato)
{
    NodoSEA *aux;
    NodoSEA *nuevo = new NodoSEA();

    aux = obtenerUltimo(lista);
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
void nodoInsertarPrincipio(NodoSEA *&lista, Almacen dato)
{
    NodoSEA *nuevo = new NodoSEA();

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
NodoSEA *obtenerUltimo(NodoSEA *lista){
    if(lista){
        while(lista->sgte){
            lista = lista->sgte;
        }
    }
    return lista;
}
void listaMostrar(NodoSEA *lista)
{
    while(lista)
    {
        cout << "codigo producto: " << lista->info.codigoProducto << endl;
        cout << "Peso: " << lista->info.peso << endl;
        lista = lista->sgte;
    }
    return;
}
void funcionArchivo(char nombreArchivo[], NodoSEA *&lista, NodoSEA *&lista2){
    FILE * f;
    NodoSEA *aux;
    Almacen info;
    Almacen *arrayDatos;
    int i=0;
    if(f=fopen(nombreArchivo, "rb")){
        aux = lista;
        while(fread(&info, sizeof(Almacen), 1, f)){
            if(info.stock == 0){
                NodoInsertarFinal(*&lista, info);
            }
            else if(info.peso > 100 && info.tipo == 'B'){
                nodoInsertarPrincipio(*&lista2, info);
            }
            i++;
            arrayDatos = new Almacen();
            arrayDatos[i-1] = info;
        }
        listaMostrar(lista);
        listaMostrar(lista2);
        fclose(f);
    }
    if(f=fopen(nombreArchivo, "w")){
        fwrite(arrayDatos, sizeof(int), i, f);
        fclose(f);
    }
}

