#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

struct Client {
    int numero;
    char cliente[51];
    int especial;
    char email[61];
    float saldo;
};
ptr_Client tabClient[MAX];

void inicializar(){
    for (int i = 0; i < MAX; ++i) {
        tabClient[i] = NULL;
    }
}

void cadastrar(int p){
    tabClient[p] = (ptr_Client)malloc(sizeof(struct Client));
    fflush(stdin);
    printf("Digite o RA do aluno: \n");
    scanf("%d", &tabClient[p]->numero);
    fflush(stdin);
    printf("Digite o cliente do aluno: \n");
    gets(tabClient[p]->cliente);
    fflush(stdin);
    printf("Digite o email do aluno: \n");
    gets(tabClient[p]->email);
    fflush(stdin);
    printf("Digite a saldo do aluno: \n");
    scanf("%f", &tabClient[p]->saldo);
    printf("Aluno cadastrado com sucesso\n");
}


void procurar(int t){
    int raProc;
    printf("Digite o RA do aluno procurado: \n");
    scanf("%d", &raProc);
    for (int i = 0; i < t; ++i) {
        if(raProc == tabClient[i]->numero){
            imprimir(i);
            return;
        }
    }
    printf("Registro nao encontrado");
}

void imprimir(int p){
    printf("Dados do aluno de RA: %d \n", tabClient[p]->numero);
    printf("cliente: %s \n", tabClient[p]->cliente);
    printf("Email: %s \n", tabClient[p]->email);
    printf("Media: %.2f \n", tabClient[p]->saldo);
    printf("------------------------------------------\n");
}

void imprimirTudo(int t){
    for (int i = 0; i < t; ++i) {
        imprimir(i);
    }
}