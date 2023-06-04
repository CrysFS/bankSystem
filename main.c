#include <stdio.h>
#include <stdlib.h>
#define MAX_CONTAS 100

typedef struct {
    int numero;
    char cliente[51];
    int especial;
    float saldo;
} Conta;

void inserir(Conta* contas, int* totalContas) {
    if (*totalContas >= MAX_CONTAS) {
        printf("Limite de contas alcançado.\n");
        return;
    }

    printf("Digite o número da conta: ");
    fflush(stdin);
    scanf("%d", &contas[*totalContas].numero);
    printf("Digite o nome do cliente: ");
    fflush(stdin);
    scanf(" %[^\n]s", contas[*totalContas].cliente);
    printf("Digite 1 se a conta é especial ou 0 se for normal: ");
    fflush(stdin);
    scanf("%d", &contas[*totalContas].especial);
    printf("Digite o saldo inicial da conta: ");
    fflush(stdin);
    scanf("%f", &contas[*totalContas].saldo);

    (*totalContas)++;
    printf("Conta inserida com sucesso!\n");
}

void alterar(Conta* contas, int totalContas) {
    int numero;
    printf("Digite o número da conta a ser alterada: ");
    fflush(stdin);
    scanf("%d", &numero);

    int encontrou = 0;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == numero) {
            printf("Digite o novo nome do cliente: ");
            fflush(stdin);
            scanf(" %[^\n]s", contas[i].cliente);
            printf("Dados da conta alterados com sucesso!\n");
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("Conta não encontrada.\n");
    }
}

void procurar(Conta* contas, int totalContas) {
    int numero;
    printf("Digite o número da conta a ser procurada: ");
    fflush(stdin);
    scanf("%d", &numero);

    int encontrou = 0;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == numero) {
            printf("Dados da conta:\n");
            printf("Número: %d\n", contas[i].numero);
            printf("Cliente: %s\n", contas[i].cliente);
            printf("Especial: %s\n", contas[i].especial ? "1" : "0");
            printf("Saldo: %.2f\n", contas[i].saldo);
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("Conta não encontrada.\n");
    }
}

void listar(Conta* contas, int totalContas) {
    printf("Lista de contas:\n");
    for (int i = 0; i < totalContas; i++) {
        printf("Número: %d\n", contas[i].numero);
        printf("Cliente: %s\n", contas[i].cliente);
        printf("Especial: %s\n", contas[i].especial ? "1" : "0");
        printf("Saldo: %.2f\n", contas[i].saldo);
        printf("---------\n");
    }
}

void depositar(Conta* contas, int totalContas) {
    int numero;
    printf("Digite o número da conta para realizar o depósito: ");
    fflush(stdin);
    scanf("%d", &numero);

    int encontrou = 0;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == numero) {
            float valor;
            printf("Digite o valor a ser depositado: ");
            fflush(stdin);
            scanf("%f", &valor);

            contas[i].saldo += valor;
            printf("Depósito realizado com sucesso!\n");
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("Conta não encontrada.\n");
    }
}

void sacar(Conta* contas, int totalContas) {
    int numero;
    printf("Digite o número da conta para realizar o saque: ");
    fflush(stdin);
    scanf("%d", &numero);
    
    int encontrou = 0;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == numero) {
            float valor;
            printf("Digite o valor a ser sacado: ");
            fflush(stdin);
            scanf("%f", &valor);

            if (valor > contas[i].saldo) {
                printf("Saldo insuficiente.\n");
            } else {
                contas[i].saldo -= valor;
                printf("Saque realizado com sucesso!\n");
            }

            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("Conta não encontrada.\n");
    }
}

void imprimir(Conta* contas, int totalContas) {
    int numero;
    printf("Digite o número da conta a ser impressa: ");
    fflush(stdin);
    scanf("%d", &numero);
    

    int encontrou = 0;
    for (int i = 0; i < totalContas; i++) {
        if (contas[i].numero == numero) {
            printf("Dados da conta:\n");
            printf("Número: %d\n", contas[i].numero);
            printf("Cliente: %s\n", contas[i].cliente);
            printf("Especial: %s\n", contas[i].especial ? "Sim" : "Não");
            printf("Saldo: %.2f\n", contas[i].saldo);
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("Conta não encontrada.\n");
    }
}

void saldoGeral(Conta* contas, int totalContas) {
    float saldoTotal = 0;
    for (int i = 0; i < totalContas; i++) {
        saldoTotal += contas[i].saldo;
    }

    printf("Saldo geral de todas as contas: %.2f\n", saldoTotal);
}

int main() {
    Conta contas[MAX_CONTAS];
    int totalContas = 0;
    int opcao;

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
        fflush(stdin);
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