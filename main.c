#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Conta *ptr_conta;

typedef struct Conta{
    int numero;
    char cliente[51];
    int especial;
    float saldo;
} Conta;

ptr_conta contas[MAX];

void inicializar() {
    for (int i = 0; i < MAX; ++i) {
        contas[i] = NULL;
}

void inserir(Conta *contas, int *totalContas) {
    (*totalContas)++;
}

void alterar(Conta *contas, int totalContas) {

}

void procurar(Conta *contas, int totalContas) {

}

void listar(Conta *contas, int totalContas) {

}

void depositar(Conta *contas, int totalContas) {

}

void sacar(Conta *contas, int totalContas) {

}

void imprimir(Conta *contas, int totalContas) {

}

void saldoGeral(Conta *contas, int totalContas) {

}

int main() {

    int totalContas = 0;
    int opcao;

    inicializar(contas);

    do {
        printf("\n----- Menu -----\n");
        printf("1. Inserir nova conta\n");
        printf("2. Alterar dados de uma conta\n");
        printf("3. Procurar uma conta\n");
        printf("4. Listar todas as contas\n");
        printf("5. Realizar depósito\n");
        printf("6. Realizar saque\n");
        printf("7. Imprimir dados de uma conta\n");
        printf("8. Mostrar saldo geral\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir(contas, &totalContas);
                break;
            case 2:
                alterar(contas, totalContas);
                break;
            case 3:
                procurar(contas, totalContas);
                break;
            case 4:
                listar(contas, totalContas);
                break;
            case 5:
                depositar(contas, totalContas);
                break;
            case 6:
                sacar(contas, totalContas);
                break;
            case 7:
                imprimir(contas, totalContas);
                break;
            case 8:
                saldoGeral(contas, totalContas);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}