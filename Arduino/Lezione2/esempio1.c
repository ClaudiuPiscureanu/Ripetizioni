// ESEMPIO 1: LIVELLO PRINCIPIANTE
// Funzione semplice per calcolare la somma di due numeri
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num1, num2;
    char operatore;
    double risultato;
    
    // Controlla che siano stati passati esattamente 3 argomenti
    if (argc != 4) {
        printf("Uso: %s numero operatore numero\n", argv[0]);
        printf("Esempio: %s 3 + 4\n", argv[0]);
        return 1;
    }
    
    // Converte gli argomenti
    num1 = atoi(argv[1]);        // primo numero
    operatore = argv[2][0];      // operatore (primo carattere del secondo argomento)
    num2 = atoi(argv[3]);        // secondo numero
    
    // Verifica che gli argomenti numerici siano validi
    if ((num1 == 0 && argv[1][0] != '0') || (num2 == 0 && argv[3][0] != '0')) {
        printf("Errore: gli argomenti devono essere numeri validi!\n");
        return 1;
    }
    
    // Esegue l'operazione in base all'operatore
    switch (operatore) {
        case '+':
            risultato = num1 + num2;
            printf("%d %c %d = %.2f\n", num1, operatore, num2, risultato);
            break;
            
        case '-':
            risultato = num1 - num2;
            printf("%d %c %d = %.2f\n", num1, operatore, num2, risultato);
            break;
            
        case '*':
            risultato = num1 * num2;
            printf("%d %c %d = %.2f\n", num1, operatore, num2, risultato);
            break;
            
        case '/':
            if (num2 == 0) {
                printf("Errore: divisione per zero non consentita!\n");
                return 1;
            }
            risultato = (double)num1 / num2;
            printf("%d %c %d = %.2f\n", num1, operatore, num2, risultato);
            break;
            
        default:
            printf("Errore: operatore '%c' non supportato!\n", operatore);
            printf("Operatori supportati: +, -, *, /\n");
            return 1;
    }
    
    return 0;
}
