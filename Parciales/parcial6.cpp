#include <iostream>

using namespace std;

void invertir(bool matriz[][8])
{
    bool invertida[8][8];

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;i++)
        {
            invertida[i][j] = matriz[7-i][j];
        }
    }

}