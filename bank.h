#ifndef PROJETOALUNO_ALUNO_H
#define PROJETOALUNO_ALUNO_H
#define MAX 100

typedef struct Aluno *ptr_aluno;
/**
 * Método para inicializar o vetor de ponteiros
 */
void inicializar();

/**
 * Parametro p = a posicao do vetor onde vou colocar
 * a referencia para o dado
 * @param p
 */
void cadastrar(int p);

/**
 * Pede ao usuario o ra do aluno a encontrar
 * e percorre o vetor até o limite atual
 */
void procurar(int t);

/**
 * Imprime apenas um cuja posicao foi passada
 */
void imprimir(int p);

/**
 * Imprime todos os alunos cadastrados
 * @param t  tamanho do vetor a ser considerado
 */
void imprimirTudo(int t);

#endif //PROJETOALUNO_ALUNO_H