#include<iostream>

using namespace std;

int main (void)
{
    int num = 0;
    float num_quinta, num_resto, num_septima = 0;

    cout << "Ingrese un numero para caluclar su quinta parte, el resto de su divicion por 5 y la septima parte del resultado dado en el primer item" << endl;
    cin >> num;

    num_quinta = num/5;
    num_resto = num%5;
    num_septima = num_quinta/7;

    cout << "La quinta parte es: " << num_quinta << "\nEl resto de su divicion por 5 es: " << num_resto << "\nLa septima parte de la primer cuenta es: " << num_septima << endl;

    return 0;
}