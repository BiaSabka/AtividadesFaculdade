// Lista Duplamente Encadeada: 
//    * Insira elementos na lista 
//    * Faça a impressão deles.
//    * Crie um menu de opções.

#include <iostream>
#include <stdlib.h> // necessário para usar o malloc

using namespace std;

// estrutura dos dados (nó)
struct no {
    int chave;           // a informação/valor que queremos guardar
    struct no *prox;     // aponta para o próximo nó na fila
    struct no *ant;      // aponta para o nó ANTERIOR
};

// apelido para facilitar 
typedef struct no NO;

// cabeça do código
typedef struct {
    NO *inicio; // aponta sempre para o primeiro elemento da lista
    int tam;    // quantidade de elementos na lista
} LISTA;

//inicializa a lista
void init(LISTA *l) {
    l->inicio = NULL; // a lista começa vazia 
    l->tam = 0;       // o tamanho inicial é zero
}

// insere no início 
void insere_ini(LISTA *l, int valor) {
    // criando um novo nó na memória
    NO *novo = (NO*) malloc(sizeof(NO));
    
    // preenchendo o novo nó
    novo->chave = valor; // coloca o número lá dentro
    novo->ant = NULL;    // como ele vai ser o primeiro, não tem ninguém antes dele
    novo->prox = l->inicio; // o próximo dele vai ser o antigo "primeiro" da lista
    
    // se a lista já tinha alguém, esse antigo "primeiro" precisa saber que agora existe alguém antes dele
    if (l->inicio != NULL) {
        l->inicio->ant = novo;
    }
    
    // a lista aponta para o novo nó como sendo o primeiro
    l->inicio = novo; 
    l->tam++; // aumentando o contador de tamanho
}

// insere no fim
void insere_fim(LISTA *l, int valor) {
    // criar e prepara o novo nó
    NO *novo = (NO*) malloc(sizeof(NO));
    novo->chave = valor;
    novo->prox = NULL;
    // caso a lista estiver vazia
    if (l->inicio == NULL) {
        novo->ant = NULL; // não tem ninguém antes
        l->inicio = novo; // ele vira o primeiro
    }
    // caso não estiver vazia
    else {
        NO *atual = l->inicio; // começamos a busca do início
        //  busca de nó em nó até achar aquele que próximo é nulo
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        // depois de achar o último, faz as conexões:
        atual->prox = novo;  // o antigo último agora aponta para o novo
        novo->ant = atual;   // o novo reconhece o antigo último como seu "anterior"
    }

    l->tam++; // atualiza a quantidade
}


// imprime a lista
void imprime(LISTA *l) {
    if (l->inicio == NULL) {
        cout << "\nA lista esta completamente vazia!\n" << endl;
        return; 
    }
    NO *atual = l->inicio;
    NO *ultimo = NULL;

    // imprime do início ao fim 
    cout << "\n>>> Imprimindo do INICIO ao FIM >>>" << endl;
    while (atual != NULL) {
        cout << "Chave: " << atual->chave << endl;
        ultimo = atual; // guarda esse nó antes de pular para o próximo
        atual = atual->prox;
    }

    // imprime do fim ao início
    cout << "\n<<< Imprimindo do FIM ao INICIO <<<" << endl;
    atual = ultimo; // Ccomeça de trás para frente
    while (atual != NULL) {
        cout << "Chave: " << atual->chave << endl;
        atual = atual->ant; // volta para o anterior
    }
    
    cout << "\nTamanho total da lista: " << l->tam << "\n" << endl;
}


int main() {
    // criação e inicialização
    LISTA minhaLista;
    init(&minhaLista);
    
    int opcao = 0; // guarda o que o usuário digitar no menu
    int valor;     // guarda o número que o usuário quer inserir

    // Estrutura de repetição para o menu ficar rodando
    do {
        cout << "===============================" << endl;
        cout << "  LISTA DUPLAMENTE ENCADEADA   " << endl;
        cout << "===============================" << endl;
        cout << "1 - Inserir um Numero no Inicio" << endl;
        cout << "2 - Inserir um Numero no Final" << endl;
        cout << "3 - Mostrar a Lista" << endl;
        cout << "0 - Sair do Programa" << endl;
        cout << "===============================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // compara a opção escolhida
        switch(opcao) {
            case 1:
                cout << "Digite o valor para inserir no inicio: ";
                cin >> valor;
                insere_ini(&minhaLista, valor);
                cout << "-> Valor " << valor << " inserido com sucesso!\n" << endl;
                break;
                
            case 2:
                cout << "Digite o valor para inserir no final: ";
                cin >> valor;
                insere_fim(&minhaLista, valor);
                cout << "-> Valor " << valor << " inserido com sucesso!\n" << endl;
                break;
                
            case 3:
                imprime(&minhaLista);
                break;
                
            case 0:
                cout << "Saindo do programa... Ate mais!" << endl;
                break;
                
            default: // Caso o usuário digite tipo '9' ou '5'
                cout << "Opcao Invalida! Tente novamente.\n" << endl;
        }
        
    } while (opcao != 0); // o loop só para quando o usuário digitar "0"

    return 0;
}