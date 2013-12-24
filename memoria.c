#include <stdio.h>
#include <stdlib.h>

void clear()
{
    system("cls");
}

int main()
{
    int opcao;
    FILE* ficp = NULL;

    ficp = fopen("mem.txt","rw+");
    do {
        clear();
        printf("# Memoria #\n1. Consultar numero\n2. Consultar nome\n3. Inserir valores\n4. Sair\n\nopcao: ");
        scanf("%d",&opcao);

        if(opcao==1) {

        }
    } while (opcao != 4);

    return 0;
}
