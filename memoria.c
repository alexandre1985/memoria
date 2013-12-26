#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 40

void clear()
{
    system("cls");
}
void limpabuffer() {
    scanf("%*[^\n]");
    scanf("%*c");
}

int main()
{
    int opcao, numero=0, numero1=-2;
    char nome[MAX_SIZE], nome1[MAX_SIZE];
    FILE *ficp = NULL, *ficp1;


    do {
        clear();
        printf("# Memoria #\n1. Consultar pelo numero\n2. Consultar pelo nome\n3. Inserir valores\n4. Imprimir tudo\n5. Sair\n\nopcao: ");
        scanf("%d",&opcao);

        /* opcao consultar pelo numero*/
        if(opcao==1) {
            clear();
            printf("numero: ");
            scanf("%d", &numero1);
            ficp = fopen("mem.txt","r");
            while (fscanf(ficp,"%d %s",&numero, nome) != EOF && numero != numero1)
                ;
            fclose(ficp);
            if(numero == numero1)
                printf("%s",nome);
            getchar();
            getchar();
        }
        if(opcao==2) {
            clear();
            printf("nome: ");
            limpabuffer();
            scanf("%s", nome1);
            ficp = fopen("mem.txt","r");
            while (fscanf(ficp,"%d %s",&numero, nome) != EOF && strcmp(nome,nome1))
                ;
            fclose(ficp);
            if(strcmp(nome,nome1) == 0)
                printf("%d\n",numero);
            getchar();
            getchar();
        }
        /* opcao inserir valores*/
        if(opcao==3) {
            clear();
            printf("numero: ");
            scanf("%d", &numero);
            printf("nome: ");
            scanf("%s", nome);
            ficp = fopen("mem.txt","a");
            fprintf(ficp, "%d %s\n", numero, nome);
            fclose(ficp);
        }
        /* opcao imprimir tudo*/
        if(opcao == 4) {
            clear();
            ficp1 = fopen("mem.txt","r");
            while (fscanf(ficp1, "%d %s", &numero, nome) != EOF)
                printf("%d %s\n", numero, nome);
            fclose(ficp1);
            getchar();
            getchar();
        }
    } while (opcao != 5);

    return 0;
}
