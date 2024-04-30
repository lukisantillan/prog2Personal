#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
//2

int multiplicacion(int numero, int exponente) {
    int resultado;   
    if (exponente == 1)
    {
        return numero;
    }
    resultado = numero + multiplicacion(numero, exponente -1);
    return resultado;
}

//3
int fibonacci(int k){
    if (k <= 1) {return k;}
    return fibonacci(k-1) + fibonacci(k-2); 
}


//4 falta negativos
double division(float m, float n){
    double result = 1;
    if (m < n && m > 0)
    {
        if (fmod(m,n) == 0)
        {
            return result;
        } else return result - 1 + m/n;
    }

    result += division(m - n, n);
    return result;
}


//6
void mafiaChina(int lvl) {
    if (lvl <= 0) {
        printf("Delegación inválida.\n");
        return;
    }

    // Caso base
    if (lvl == 1) {
        printf("(-.-)");
        return;
    }

    // Dibujar la parte izquierda de la delegación
    printf("(-.");

    // Llamada recursiva para dibujar la delegación interior
    mafiaChina(lvl - 1);

    // Dibujar la parte derecha de la delegación
    printf(".-)");
}


#include <stdio.h>
#include <stdlib.h> // Para malloc
#include <string.h> // Para strlen y strcat

char* señales2(const char *señal) {
    // Caso base: si llegamos al final de la cadena, retornamos una cadena vacía
    if (*señal == '\0') {
        char *resultado = malloc(1 * sizeof(char));
        if (resultado == NULL) {
            printf("Error: No se pudo reservar memoria.\n");
            exit(1);
        }
        *resultado = '\0';
        return resultado;
    }

    // Asignamos memoria para el resultado actual
    char *resultado = malloc(2 * sizeof(char)); // Solo necesitamos espacio para un carácter y el nulo
    if (resultado == NULL) {
        printf("Error: No se pudo reservar memoria.\n");
        exit(1);
    }
    // Asignamos el carácter correspondiente según el primer carácter de la señal
    if (*señal == 'H') {
        *resultado = '-';
    
    } 
    if (*señal == 'L') {
        *resultado = '_';
    } 
    if (*(señal + 1) != '\0' && *señal != *(señal + 1)) {
        *resultado = '|';
    }
   
    *(resultado + 1) = '\0'; // Agregamos el carácter nulo al final

    // Realizamos la llamada recursiva con el resto de la cadena y concatenamos el resultado actual con el resultado de la llamada recursiva
    char *resto = señales2(señal + 1);
    resultado = realloc(resultado, (strlen(resultado) + strlen(resto) + 1) * sizeof(char)); // Redimensionamos la memoria para el resultado actual
    strcat(resultado, resto);
    free(resto);

    return resultado;
}

//7 
void señales(char *señal){
    if (*señal == '\0')
    {
        return;
    }
    if (*señal == 'H')
    {
        printf("¯");
    }
    if (*señal == 'L')
    {
        printf("_");
    }
    if (*(señal + 1) != '\0' && *señal != *(señal + 1)) {
        printf("|");
    }
    return señales(señal + 1);
}

//9
int numeroDivisiblePor7(int N){
    if (N < 70)
    {
        if (N % 7 == 0)
        {
            printf("Es divisible por 7");
        } else {printf("No es divisible por 7");}
        
        return N;
    }
    int ultimoDigito = N % 10;
    int resultado = numeroDivisiblePor7(N/10 - ultimoDigito * 2);
    return resultado;
}

 //10
void bomba(int A, int B){
    int resultado;
    if (A <= B)
    {
        printf(" %i", B);
    
        return;
    }

    int n1 = A / B;
    int n2 = A - (A/B);

    if (n1 > B)
    {
        resultado = n1;
    } else {
        printf(" %i", n1);
    
    }
    if (n2 >= B)
    {
        resultado = n2;
    } else {
        printf(" %i", n2);
        }
    return bomba(resultado, B);

}


int main()
{
    char *resultado = señales2("HLHLH");
    printf("Resultado: %s\n", resultado);
    return 0;
}
