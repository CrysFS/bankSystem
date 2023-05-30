#include <stdio.h>
#include "bank.h"

int main() {
    int i = 0;
    int opcao=0;
    inicializar();
    do{
        printf("Menu principal\n");
        printf("1. Cadastrar Aluno \n");
        printf("2. Procurar Aluno \n");
        printf("3. Lista todos \n");
        printf("9. Sair \n");
        printf("Digite sua opcao: \n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrar(i);
                i++;
                break;
            case 2:
                procurar(i);
                break;
            case 3:
                imprimirTudo(i);
                break;
            case 9:
                printf("Fim do programa\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(opcao!=9);

    return 0;
}
