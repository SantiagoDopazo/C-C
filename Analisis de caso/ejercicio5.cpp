#include<iostream>

using namespace std;

int main(void)
{
    int num1, num2 = 0;

    cout << "Ingrese dos numeros para comprobar cual es mayor" << endl;
    cin >> num1;
    cin >> num2;

    if(num1 > num2)
    {
        cout << num1 << " Es mayor que " << num2 << endl;
    }
    else if(num2 > num1)
    {
       cout << num2 << " Es mayor que " << num1 << endl; 
    }
    else
    {
        cout << num1 << " = " << num2 << endl; 
    }

    return 0;
}