#include <iostream>

using namespace std;

int nuevaLectura(long int codigo[2][100], int indice, long int nuevo)
{
    if(indice<100)
    {
        codigo[indice][0] = nuevo;
    }
    else
    {
        return -1;
    }
    return 0;
}
void validar(long int codigo[100][2])
{
    for(int i=0;i<100;i++)
    {
        if(codigo[i][0] == 0)
        {
            for(int j=0;j<99;i++)
            {
                codigo[j][0] = codigo[j+1][0];
                codigo[j][1] = codigo[j+1][1];
            }
        }
    }
}
void ordenar(long int codigo[2][100])
{
    int aux;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100-i;i++)
        {
            if(codigo[j][1]> codigo[j+1][1])
            {
                aux = codigo[j+1][1];
                codigo[j+1][1] = codigo[j][1];
                codigo[j][1] = aux;

                aux = codigo[j+1][0];
                codigo[j+1][0] = codigo[j][0];
                codigo[j][0] = aux;
            }
        }
    }
}