#include <iostream>
#include <string>

using namespace std;

struct persona{
    int celular;
    char nombre [20];
    char dirreccion [25];
    int tiempo;
    char abono;
}Persona[10];

int toMin(int t){
    return (t/100)*60 + t%100; // t = 1020 divido 100 me da las horas = 10 y 1020 % 100 me da los minutos
};
void calcularCosto(int abono, int minLibres, int cargoExcedente, int minUtilizados, int &minExedidos, int &montoTotal){
    if(minLibres-minUtilizados < 0){
        minExedidos=minLibres - minUtilizados;
    }
    else{
        minExedidos = 0;
    }
    montoTotal = abono + minExedidos * cargoExcedente;
    montoTotal += montoTotal*0.21;
}
int main(){
    int cantidad, i = 0;
    cout << "Cuantas personas vas a ingresar" << endl;
    cin >> cantidad;
    for(i=0;i<cantidad;i++){
        cout << "Ingresar  numero de celular" << endl;
        cin >> Persona[i].celular;
        cout << "Ingresar nombre del abonado"<< endl;
        cin >> Persona[i].nombre;
        cout << "Ingrese la direccion del abonado" << endl;
        cin >> Persona[i].dirreccion;
        cout << "Ingresar el tiempo utilizado en formato hhmm" << endl;
        cin >> Persona[i].tiempo;
        cout << "Ingrese el tipo de abono A B C D o E" << endl;
        cin >> Persona[i].abono;
    }
    
    
    cout<< toMin(1020) << endl;
    return 0;
};
