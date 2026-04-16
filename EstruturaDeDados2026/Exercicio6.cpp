// Insira elementos na lista e faça ela imprimir os resultados.

#include <iostream>
#include <stdlib.h> // trabalhar com nó

using namespace std;

// estrutura dos nossos dados
// agenda
struct address {
    int chave;
    //outros campos
    char nome[30];
    char rua[30];
    char email[80];
    struct address *prox;
};
// defino que a estrutura da agenda é um nó
typedef struct address no;

// Lista de controle (cabeça)
typedef struct {
    no *inicio; // aponta para o início
    int tam;    // quantidade de elementos na lista
}LISTA;
// Métodos que vamos utilizar
// 1 - inicializar
// 2 - inserir no início
// 3 - inserir no final
// 4 - imprimir
// 5 - remover

// inicializar
void init(LISTA *l) {
    l->inicio = NULL;
    l->tam = 0;
}
// inserir no início
// passando um valor
void insere_ini(LISTA *l, int valor){
    // PRIMEIRA tarefa: Criar um novo nó
    // NECESSÁRIO fazer um cast para nó
    // '1010' -> cast para inteiro 1010
    no *novo = (no*) malloc(sizeof(no));
    // inserir a chave no novo nó
    novo->chave = valor;
    // JUMP OF THE CAT
    // o próximo do novo aponta o início da Lista
    novo->prox = l->inicio;
    // o início da lista agora deve ser o novo nó
    l->inicio = novo; 
    // atualiza a quantidade de elemento
    l->tam++;
}
// Inserir no fim
void insere_fim(LISTA *l, int valor) {
    // Criar um novo nó
    no *novo = (no*) malloc(sizeof(no));
    no *atual;
    // insere o valor novo ao nó criado
    novo->chave = valor;
    // o próximo do novo é NULL
    novo->prox = NULL;

    // precisa percorrer a lista até chegar
    //.. no nó onde o próximo é Nulo

    // Verificar se a lista é vazia
    if (l->inicio == NULL){
       l->inicio = novo; // o novo é início
    } else {// se não for vazia
        atual = l->inicio;
        //enquanto houver elementos próximos na lista
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        // chegou no último elemento
        atual->prox = novo;
    }
    // atualiza a quantidade de elementos
    l->tam++;
}

void imprime(LISTA *l) {
    no *atual;
    atual = l->inicio;
    cout << "Tamanho da lista: " << l->tam << endl;
    while (atual != NULL){
        cout << "Chave: " << atual->chave << endl;
        atual=atual->prox;
    }
}

int main()
{
    // Criação da minha lista
    LISTA minhaLista;

    // Inicialização da lista
    init(&minhaLista);

    // Insere elementos no início
    insere_ini(&minhaLista, 10);
    insere_ini(&minhaLista, 20);

    // Insere elementos no fim
    insere_fim(&minhaLista, 30);
    insere_fim(&minhaLista, 40);

    // Imprime os resultados na tela
    imprime(&minhaLista);

    return 0;
}