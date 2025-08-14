
// ESEMPIO 2: LIVELLO INTERMEDIO
// Funzioni con array e passaggio per riferimento

#include <stdio.h>

// Funzione per calcolare la media di un array
float calcolaMedia(int arr[], int dimensione) {
    int somma = 0;
    for(int i = 0; i < dimensione; i++) {
        somma += arr[i];
    }
    return (float)somma / dimensione;
}

// Funzione per trovare il valore massimo e minimo (passaggio per riferimento)
void trovaMinMax(int arr[], int dimensione, int *min, int *max) {
    *min = *max = arr[0];
    
    for(int i = 1; i < dimensione; i++) {
        if(arr[i] < *min) {
            *min = arr[i];
        }
        if(arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int numeri[] = {12, 45, 7, 23, 89, 34, 56};
    int dimensione = sizeof(numeri) / sizeof(numeri[0]);
    int minimo, massimo;
    
    float media = calcolaMedia(numeri, dimensione);
    trovaMinMax(numeri, dimensione, &minimo, &massimo);
    
    printf("Array: ");
    for(int i = 0; i < dimensione; i++) {
        printf("%d ", numeri[i]);
    }
    printf("\n");
    
    printf("Media: %.2f\n", media);
    printf("Minimo: %d\n", minimo);
    printf("Massimo: %d\n", massimo);
    
    return 0;
}
