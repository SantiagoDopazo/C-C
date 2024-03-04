#include<iostream>

using namespace std;

int main()
{
    int day, month, year, date =0;

    cout << "Ingrese la fecha de un dia\nIngrese el dia: " << endl;
    cin >> day;
    cout << "\nIngrese el mes:" << endl;
    cin >> month;
    cout << "\nIngrese el anio:" << endl;
    cin >> year;

    //se podria hacer un if para comprobar si los datos son numeros.

    date = (year*10000)+(month*100)+day;
    
    cout << "La fecha es:" << date << endl;

    return 0;
}
