#include <stdio.h>

#define MAX 100

// Prototipos de funciones
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void imprimirArreglo(int arr[], int n);

int main() {
    int arreglo[MAX], n, opcion;

    printf("Ingrese el numero de elementos (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Cantidad invalida.\n");
        return 1;
    }

    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    printf("\nElija el metodo de ordenamiento:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            selectionSort(arreglo, n);
            printf("\nArreglo ordenado con Selection Sort:\n");
            imprimirArreglo(arreglo, n);
            break;
        case 2:
            insertionSort(arreglo, n);
            printf("\nArreglo ordenado con Insertion Sort:\n");
            imprimirArreglo(arreglo, n);
            break;
        default:
            printf("Opcion invalida.\n");
            return 1;
    }

    return 0;
}

// ---------------- Selection Sort ----------------
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// ---------------- Insertion Sort ----------------
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ---------------- Imprimir arreglo ----------------
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
