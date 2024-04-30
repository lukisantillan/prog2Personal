#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE * demo;
    int a, b, c, d;
    int linea = 0;
    demo = fopen("demo_file.txt", "r");
    while (!feof(demo))
    {
        fscanf(demo, "%d %d %d %d", &a,&b,&c,&d);
        fprintf(demo, "%d %d %d %d\n", a,b,c,d);
        linea++;
    }
    printf("-- FIN DE ARCHIVO --  %d Lineas Leidas", linea);
    fclose(demo);
    system("pause");
    return 0;
}
