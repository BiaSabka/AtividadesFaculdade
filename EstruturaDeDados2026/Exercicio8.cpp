// Crie um método de inserir elementos no início;
// Deve-se implementar a lógica para adicionar um novo elemento na primeira posição da lista.


#include <iostream>
#include <stdlib.h> 

using namespace std;

// estrutura nó duplo 
struct no {
    int chave;
    struct no *prox;
    struct no *ant;
};
typedef struct no NO;

// estrutura da lista
typedef struct {
    NO *inicio;
    int tam;
} LISTA;

// função que inicia a lista vazia
void init(LISTA *l) {
    l->inicio = NULL;
    l->tam = 0;
}

void insereInicio(LISTA *l, int valor) {
    // cria o nó
    NO *novo = (NO*) malloc(sizeof(NO)); 
    
    // guarda o valor
    novo->chave = valor;
    // ninguém antes do primeiro
    novo->ant = NULL;      
    // o próximo é o antigo primeiro
    novo->prox = l->inicio;             
    
    // se ja tinha um na lista,ele aponta pro novo
    if (l->inicio != NULL) {             
        l->inicio->ant = novo;           
    }
    
    // o novo vira o início
    l->inicio = novo;   
    // aumenta o tamanho da lista
    l->tam++;                            
}

// imprime a lista
void imprime(LISTA *l) {
    // começa pelo início
    NO *atual = l->inicio;
    
    cout << "--- Itens na Lista (Tamanho: " << l->tam << ") ---" << endl;
    
    // vai pulando de um em um até chegar no NULL
    while (atual != NULL) {
        cout << "Valor: " << atual->chave << endl;
        atual = atual->prox;
    }
    cout << "---------------------------------" << endl;
}

int main() {
    LISTA minhaLista;
    init(&minhaLista);

    // o último a ser inserido será o primeiro a aparecer
    cout << "Inserindo o numero 10 no inicio..." << endl;
    insereInicio(&minhaLista, 10);
    
    cout << "Inserindo o numero 20 no inicio..." << endl;
    insereInicio(&minhaLista, 20);
    
    cout << "Inserindo o numero 30 no inicio...\n" << endl;
    insereInicio(&minhaLista, 30);

    imprime(&minhaLista);

    return 0;
}