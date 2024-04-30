#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * demo;
    int display;
    demo = fopen("demo_file.txt", "r");
    while (!feof(demo))
    {
        display = fgetc(demo);
        printf("%c", display);
    }
    printf("-- FIN DE ARCHIVO --");
    fclose(demo);
    system("pause");
    
    return 0;
}

//FEOF DEVUELVE 0 SIEMPRE QUE NO ESTE EN EL FIN DE ARCHIVO Y DEVUELVE UN NUMERO DISTINTO A 0 SI ES EL FIN DE ARCHIVO