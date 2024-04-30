#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[] = "Hola,mundo,soy,una,cadena,separada,por,comas";
    int longitud = strlen(cadena);
    char delimitador[] = ",";
    char *token = strtok(cadena,delimitador);
    while (token != NULL)
    {
        printf("token: %s\n", token);
        token = strtok(NULL, delimitador);
    }
    
    printf("Area de memoria:    \n");
    for (int i = 0; i < longitud; i++)
    {
        printf("cadena[%d]: %c - %d\n", i, cadena[i],cadena[i]);
    }
    
    char c = getchar();
    return 0;
}

/*
Detalles sobre strtok:
    *destruye el string
    *ingnora los delimitadores inicilaes de la cadena
    *coloca \0 en lugar del delimitador que va encontrando.
*/
