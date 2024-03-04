#include<iostream>

using namespace std;

int main(void)
{
    int day, month, year, date = 0;
    cout << "Ingrese una fecha deseada de la siguiente manera AAAAMMDD " << endl;
    cin >>date;

    year = date/10000;
    month = (date-year*10000)/100;
    day = (date-year*10000-month*100);

    cout << "El dia es: " << year << "\nEl mes es: " << month << "\nEl dia es: " << day << endl;

    return 0;
} 
    
