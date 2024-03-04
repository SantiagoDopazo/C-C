#include <stdio.h>
#include <string.h>

typedef struct {
    int ID_Modelo;
    char Comprador[21];
    char Fecha[5];
} Registro;

void swap(Registro *xp, Registro *yp) {
    Registro temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Registro arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].ID_Modelo > arr[j + 1].ID_Modelo) {
                swap(&arr[j], &arr[j + 1]);
            }
            else if (arr[j].ID_Modelo == arr[j + 1].ID_Modelo) {
                // si los ID_Modelo son iguales, ordenar por Fecha en formato DDMM
                if (strcmp(arr[j].Fecha, arr[j + 1].Fecha) > 0) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}

void imprimirVector(Registro arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %s\n", arr[i].ID_Modelo, arr[i].Comprador, arr[i].Fecha);
    }
}

int main() {
    Registro arr[100] = {
        {1, "Comprador1", "0222"},
        {1, "Comprador2", "0401"},
        {2, "Comprador3", "0522"},
        {3, "Comprador4", "0101"},
        {3, "Comprador5", "0315"},
        {3, "Comprador6", "0601"}
        // agregar el resto de los registros...
    };
    int n = 6; // cantidad de registros en el vector
    bubbleSort(arr, n);
    imprimirVector(arr, n);
    return 0;
}
