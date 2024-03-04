#include <iostream>

using namespace std;

struct producto
{
    int cantv;
    int precio;
    char vec_desc[50];
}Productos[100];

void Cargaprods (producto Productos[], int n)
{
    int i = 0;

    for(i=0;i<n;i++)
    {
        cout << "Ingrese la Descripcion del producto" << i+1 << endl;
        getchar();
        fflush(stdin);
        fgets(Productos[i].vec_desc, 50, stdin);
        fflush(stdin);
        cout << "Ingrese el precio unitario del producto" << i+1 << endl;
        cin >> Productos[i].precio;
        Productos[i].cantv=0;

    }
}
void ProcesaVentas(producto Productos[], int n)
{
    int i = 1;
    while(i!=0)
    {
        cout << "Ingrese codigo de producto entre 1 y "<< n << endl;
        cin >> i;

        if(i != 0)
        {
            cout << "Ingrese cantidad vendida del producto" << endl;
            cin >> Productos[i-1].cantv;
        }
    }
}

int main ()
{
    int documento = 0,  n = 0;
    cout << "introduce el ultimo numero del DNI" << endl;
    cin >> documento;
    cout << "Ingrese la cantidad de productos que maneja el comercio" << endl;
    cin >> n;

    /*if(documento <= 4 && documento >= 0)
    {
        Cargaprods(Productos, n);
    }
    else if(documento >= 5 && documento <= 9 )
    {
        ProcesaVentas(Productos, n);
    }
    else
    {
        cout << "Numero invalido de DNI" << endl;
    }*/

    Cargaprods(Productos, n);
    ProcesaVentas(Productos, n);


    for (int i = 0; i < n; i++)
    {
        cout << "Producto:" << i+1 << "\nCantidad vendida: " << Productos[i].cantv << "\nPrecio Unitario: " << Productos[i].precio <<"\nDescripcion: " << Productos[i].vec_desc << endl;
        
    }
    
}

