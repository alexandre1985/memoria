#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 40

void clear()
{
    system("cls");
}

int main()
{
    int opcao, numero;
    char nome[MAX_SIZE];
    FILE* ficp = NULL;

    ficp = fopen("mem.txt","rw+");
    do {
        clear();
        printf("# Memoria #\n1. Consultar qual numero\n2. Consultar qual nome\n3. Inserir valores\n4. Sair\n\nopcao: ");
        scanf("%d",&opcao);

        /* opcao consultar qual numero*/
        if(opcao==1) {
            if (ficp == NULL) {
                printf("Ficheiro ainda nao existe!");
                getchar();
                getchar();
                continue;
            }
            clear();
            printf("numero: ");
            scanf("%d", &numero);
        }
        /* opcao inserir valores*/
        if(opcao==3) {
            clear();
            printf("numero: ");
            scanf("%d", &numero);
            printf("nome: ");
            scanf("%s", nome);
            fprintf(ficp, "%d %s\n", numero, nome);
        }
    } while (opcao != 4);

    fclose(ficp);

    return 0;
}
