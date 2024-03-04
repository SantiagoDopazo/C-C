#include<iostream>
#include<cstring>

using namespace std;

void cant_vocales(char arr[],int tam);
void cant_palabras(char arr[],int tam);
void cant_letras_palabra_mayor(char arr[],int tam);

int main (void){
    char oracion[]="Hola mi nombre es Santiago mucho gusto.";
    int tam =0, vocal=0;
    
    tam=strlen(oracion)+1; //strlen no cuenta el \0
    cant_vocales(oracion, tam);
    cant_palabras(oracion, tam);
    cant_letras_palabra_mayor(oracion, tam);

    
    //cout <<"El tamanio de la oracion es: " << tam << "El sizeof" <<sizeof oracion << "el sizeof[0]" << sizeof oracion[0] << endl;
    return 0;
}

void cant_palabras(char oracion[],int tam){
    int k=0, a=0, e=0, i=0, o=0, u=0;

    for(k=0;k<tam;k++){
        
        switch (oracion[k])
        {
            case 'a':
            case 'A':
                a++;
                break;
            case 'e':
            case 'E':
                e++;
                break;
            case 'i':
            case 'I':
                i++;
                break;
            case 'o':
            case 'O':
                o++;
                break;
            case 'u':
            case 'U':
                u++;
                break;
            default:
                break;
        }
    }
    cout<< "La a se repite " << a << " veces\nLa e se repite "<< e <<" veces\nLa i se repite "<< i << " veces\nLa o se repite "<< o << " veces\nLa u se repite "<< u << " veces"<< endl;
}

void cant_vocales(char oracion[],int tam){
    int i=0, palabra=0;
    for(i=0;i<tam;i++){
        if(oracion[i]==' ' || oracion[i]=='.'){
            palabra ++;
        }
    }
    cout << "La cantidad de palabras es: " << palabra << endl;
}

void cant_letras_palabra_mayor(char oracion[],int tam){
    int i=0, k=0, letras=0, mayor=0;

    for(i=0;i<7;i++){
        while(oracion[k]!=' ' && oracion[k]!='.'){
        letras++;
        k++;
        }
        k++;
    }
    if(letras>mayor){
        mayor=letras;
    }

    cout<< "La palabra con mayor letras contiene: " << mayor << "letras" << endl;
}