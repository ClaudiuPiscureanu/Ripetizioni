
// ESEMPIO 3: LIVELLO AVANZATO
// Funzioni ricorsive e manipolazione di stringhe

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funzione ricorsiva per calcolare il fattoriale
long long fattoriale(int n) {
    if(n <= 1) {
        return 1; // caso base
    }
    return n * fattoriale(n - 1); // chiamata ricorsiva
}

// Funzione ricorsiva per invertire una stringa
void invertiStringa(char *str, int inizio, int fine) {
    if(inizio >= fine) {
        return; // caso base
    }
    
    // Scambia i caratteri
    char temp = str[inizio];
    str[inizio] = str[fine];
    str[fine] = temp;
    
    // Chiamata ricorsiva
    invertiStringa(str, inizio + 1, fine - 1);
}

// Funzione per contare le vocali in una stringa (ricorsiva)
int contaVocali(char *str, int indice) {
    if(str[indice] == '\0') {
        return 0; // caso base: fine stringa
    }
    
    char c = str[indice];
    int isVocale = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    
    return isVocale + contaVocali(str, indice + 1);
}

// Funzione per allocare dinamicamente memoria per una matrice
int** creaMatrice(int righe, int colonne) {
    int **matrice = (int**)malloc(righe * sizeof(int*));
    
    for(int i = 0; i < righe; i++) {
        matrice[i] = (int*)malloc(colonne * sizeof(int));
    }
    
    return matrice;
}

// Funzione per liberare la memoria di una matrice
void liberaMatrice(int **matrice, int righe) {
    for(int i = 0; i < righe; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

// Funzione per riempire una matrice con valori casuali
void riempiMatrice(int **matrice, int righe, int colonne) {
    for(int i = 0; i < righe; i++) {
        for(int j = 0; j < colonne; j++) {
            matrice[i][j] = rand() % 100; // valori da 0 a 99
        }
    }
}

// Funzione per stampare una matrice
void stampaMatrice(int **matrice, int righe, int colonne) {
    for(int i = 0; i < righe; i++) {
        for(int j = 0; j < colonne; j++) {
            printf("%3d ", matrice[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Test delle funzioni ricorsive
    int numero = 6;
    printf("Fattoriale di %d: %lld\n\n", numero, fattoriale(numero));
    
    char testo[] = "Programmazione";
    printf("Stringa originale: %s\n", testo);
    
    int vocali = contaVocali(testo, 0);
    printf("Numero di vocali: %d\n", vocali);
    
    invertiStringa(testo, 0, strlen(testo) - 1);
    printf("Stringa invertita: %s\n\n", testo);
    
    // Test con matrice dinamica
    int righe = 3, colonne = 4;
    int **matrice = creaMatrice(righe, colonne);
    
    riempiMatrice(matrice, righe, colonne);
    
    printf("Matrice %dx%d generata casualmente:\n", righe, colonne);
    stampaMatrice(matrice, righe, colonne);
    
    liberaMatrice(matrice, righe);
    
    return 0;
}



/*ESEMPIO 3 (Avanzato):
- Funzioni ricorsive (fattoriale, inversione stringa, conta vocali)
- Allocazione dinamica della memoria
- Gestione di matrici dinamiche
- Manipolazione avanzata di stringhe
- Gestione della memoria (malloc/free)
*/
