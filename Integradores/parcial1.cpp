#include<iostream> 
#define JUEGOS 3
#define ELEMENTOS 10
using namespace std;

int main (void){
    int i=0, n=0, k=0, j=0, h=0, r=0, s=0, suma=0, par=0;
    int pares[JUEGOS];
    cout<<"Este programa hara 10 juegos de n valores cada uno, si se ingresa 0 el juego terminara"<< endl;
    for(i=0;i<JUEGOS;i++){
        cout<< "Juego numero "<< i+1 << endl;
        n=1;
        k=0;
        j=0;
        h=0;
        s=0;
        suma=0;
        while(n!=0 && s<ELEMENTOS){
            cout<<"Ingrese el primer numero del juego"<< endl;
            cin>> n;
            if(n>=-10 && n<=10 && n!=0){
                k++;
            }
            if(n>50){
                suma+=n;
                j++;
            }
            if(n%2==0){
                h++;
            }
            s++;
        }
        if(h!=0){
            pares[i]=h;
        }
        else{
            pares[i]=0;
        }
        cout <<"Para el juego" << i+1 <<endl;
        cout <<"La cantidad de numeros entre -10 y 10 fue: "<< k <<endl;
        if(j!=0){
            cout <<"El promedio de todos los numero mayores a 50 es:"<< suma/j << endl;   
        }
    }
    for(i=0;i<JUEGOS;i++){
        if(pares[i]>par){
            par=pares[i];
            r++;
        }
    }

    cout<<"El juego con mayor numeros pares fue el " << r <<endl;

    return 0;

}

















