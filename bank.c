#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

struct Aluno {
    int ra;
    char nome[51];
    char email[61];
    double media;
};
ptr_aluno tabAlu[MAX];

void inicializar(){
    for (int i = 0; i < MAX; ++i) {
        tabAlu[i] = NULL;
    }
}

void cadastrar(int p){
    tabAlu[p] = (ptr_aluno)malloc(sizeof(struct Aluno));
    fflush(stdin);
    printf("Digite o RA do aluno: \n");
    scanf("%d", &tabAlu[p]->ra);
    fflush(stdin);
    printf("Digite o nome do aluno: \n");
    gets(tabAlu[p]->nome);
    fflush(stdin);
    printf("Digite o email do aluno: \n");
    gets(tabAlu[p]->email);
    fflush(stdin);
    printf("Digite a media do aluno: \n");
    scanf("%lf", &tabAlu[p]->media);
    printf("Aluno cadastrado com sucesso\n");
}


void procurar(int t){
    int raProc;
    printf("Digite o RA do aluno procurado: \n");
    scanf("%d", &raProc);
    for (int i = 0; i < t; ++i) {
        if(raProc == tabAlu[i]->ra){
            imprimir(i);
            return;
        }
    }
    printf("Registro nao encontrado");
}

void imprimir(int p){
    printf("Dados do aluno de RA: %d \n", tabAlu[p]->ra);
    printf("Nome: %s \n", tabAlu[p]->nome);
    printf("Email: %s \n", tabAlu[p]->email);
    printf("Media: %.2lf \n", tabAlu[p]->media);
    printf("------------------------------------------\n");
}

void imprimirTudo(int t){
    for (int i = 0; i < t; ++i) {
        imprimir(i);
    }
}