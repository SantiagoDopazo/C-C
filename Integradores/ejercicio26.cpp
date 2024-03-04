#include<iostream>
#define NUM 100

using namespace std;

struct paquete
{
    int id;
    float peso;
    int arrivo;
};

void llenar_array (paquete x[], int cant);
void mostrar_array (paquete x[], int cant);
void peso_total (paquete x[], int cant);
void id_mayorpeso( paquete x[], int cant);
void cantidad_en_puertos(paquete x[], int cant);


int main (void){
    int cant = 0;
    paquete container[NUM];
    cout << "Ingrese la cantidad de containers a cargar" << endl;
    cin >> cant;

    llenar_array (container, cant);
    mostrar_array (container, cant);
    peso_total (container,cant);
    id_mayorpeso(container, cant);
    cantidad_en_puertos(container, cant);

    return 0;
    
    

}

void llenar_array (paquete container[], int cant){
    int i =0;
    for(i=0;i<cant;i++){
        cout << "Ingrese la id del container "<< i << endl;
        cin >> container[i].id;
        cout << "Ingrese el peso del container"<< i << endl;
        cin >> container[i].peso;
        cout << "Ingrese el puerto de arrivo 1,2 o 3"<< endl;
        cin >> container[i].arrivo;
        if(container[i].arrivo>3 || container[i].arrivo<1){
            cout <<"El puerto ingresado no es valido, solo exiten los puertos 1 2 y 3, porfavor vuelva a seleccionar el puerto"<< endl;
            cout << "Ingrese el puerto de arrivo 1,2 o 3"<< endl;
            cin >> container[i].arrivo;
        }
    }
}

void mostrar_array (paquete container[], int cant){
    int i =0;
    for(i=0;i<cant;i++){
        cout <<"Container["<< i << "]La id es "<< container[i].id <<endl;
        cout <<"Container["<< i << "]Su peso en Kg es "<< container[i].peso <<endl;
        cout <<"Container["<< i << "]Puerto de arrivo: "<< container[i].arrivo <<endl;
    }
}

void peso_total (paquete container[], int cant){
    int i=0 , pesot=0;
    for(i=0;i<cant;i++){
        pesot+=container[i].peso;
    }
    cout << "El peso total es "<< pesot <<"Kg" << endl; 

}

void id_mayorpeso( paquete container[], int cant){
    int i=0, pesom=0;
    for(i=0;i<cant;i++){

        if(container[i].peso>pesom){
            pesom=container[i].id;
        }
    }
    cout << "El container con el mayor peso es el de la id: " << pesom << endl;
}

void cantidad_en_puertos(paquete container[], int cant){
    int i=0, j=0, p=0, k=0;
    for (i=0;i<cant;i++){
        switch (container[i].arrivo)
        {
        case 1: j++;
        break;
        case 2: k++;
        break;
        case 3: p++;
        break;
        default: cout << "No existe el puerto" << endl;
        break;
        }
    }
    cout << "Al puerto 1 se deben trasladar " << j << "contenedores" << endl;
    cout << "Al puerto 2 se deben trasladar " << k << "contenedores" << endl;
    cout << "Al puerto 3 se deben trasladar " << p << "contenedores" << endl;
    
    
}