//Remoção do Início (removeInicio)
// Deve-se implementar a lógica para remover o primeiro elemento da lista e liberar da memória.

#include <iostream>

using namespace std;

// criação da minha estrutura do nó
struct address {
    int chave;
    // nome, rg, cpf..

    //criação do ponteiro para a nossa estrutura
    struct address *prox;
    struct address *ant;
};
// crio um apelido para a estrutura
typedef struct address no;

// criar a estrutura da LISTA de controle
typedef struct {
    no *inicio;
    no *fim;
    int tam;
}LISTA;

// Funções para manipular a lista duplamente encadeada
// 1 - inicializar
// 2 - insere fim
// 3 - imprimir

//maloc(sizeof(no)) -> new   : criação de nó
//free(no)          -> delete: remoção
// 1 - inicializando a lista
void init(LISTA *l){
    l->inicio = nullptr;
    l->fim = nullptr;
    l->tam = 0;
}
// 2 - inserindo no fim da lista
void insereFim(LISTA *l, int valor) {
    // criar um novo nó
    no *novo = new no; // alocar

    // verificar se a lista está vazia
    if (l->inicio == nullptr) {
        // não temos nenhum elemento na LISTA
        cout << "LISTA vazia!" << endl;
        novo->prox = nullptr;
        novo->ant = nullptr;

        // atualizar a LISTA de controle
        l->inicio = novo;
        l->fim = novo;
    }
    else { // lista NÃO está vazia
        cout << "LISTA não está vazia!" << endl;
        novo->prox = nullptr;
        novo->ant = l->fim;
        // Atualizar a LISTA de controle
        //l->fim->chave (10)
        //l->fim->ant   (null)
        //l->fim->prox  (null)
        l->fim->prox = novo;
        // atualizar o novo fim
        l->fim = novo;
    }
    novo->chave = valor;
    l->tam++;
}

// 3 - impressão
void imprime(LISTA *l){
    //criar um no *atual para auxiliar percorrer na LISTA
    // no *atual ele começa no INICIO
    no *atual = l->inicio;
    cout << "Tamanho da lista: " << l->tam << endl;
    // percorrer a lista
    while (atual != nullptr){
        cout << atual->chave << " -> ";
        atual = atual->prox;
    }
    cout << "NULL";
}

void removeFim(LISTA *l){
    // Qual a primeira validação??
    // validar se a lista está vazia
    if (l->fim == nullptr) {
        cout << "Lista Vazia!!";
        return;
    }
    
    //criar um nó auxiliar
    no *atual = l->fim;
    
    // Verificar 2 situações aqui:
    // 1* se existe apenas um elemento
    if (atual->ant == nullptr){
        cout << "Existe apenas 1 elemento na lista!";
        // inicializa a lista de controle
        init(l);
    } else { // 2* se existe mais de um elemento
        // atualiza a lista de controle
        l->fim = atual->ant; //atualiza o novo fim
        
    }
    
    // remove o último elemento
    delete atual; //libera espaço na memória
}

void removeInicio(LISTA *l) {
    // validar se a lista está vazia
    if (l->inicio == nullptr) {
        cout << "Lista Vazia!!" << endl;
        return;
    }

    // criar um nó auxiliar
    no *atual = l->inicio;

    // 2 situações também (igual a de remover fim)
    // 1* se existe apenas um elemento
    if (atual->prox == nullptr) {
        cout << "Existe apenas 1 elemento na lista!";
        // inicializa a lista de controle
        init(l);
    } 
    else {
        // 2* se existe mais de um elemento
        // atualiza a lista de controle
        l->inicio = atual->prox; // atualiza novo começo
        l->inicio->ant = nullptr; 
        l->tam--; // atualiza tamanho da lista
    }

    delete atual; // libera espaço na memória
}


int main()
{
    LISTA lista1;
    init(&lista1);
    
    insereFim(&lista1, 10);
    insereFim(&lista1, 20);
    insereFim(&lista1, 30);
    
    int opcao; // variável que recebe a escolha do usuário
    
    do { // estrutura que fica se repetindo até o usuário pedir pra sair
        cout << "\n\n MENU " << endl;
        cout << "1 - imprimir lista" << endl;
        cout << "2 - remover do fim" << endl;
        cout << "3 - remover do inicio" << endl;
        cout << "0 - sair" << endl;
        cout << "\n escolha uma opcao: ";
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                imprime(&lista1);
                break;
            case 2:
                removeFim(&lista1);
                break;
            case 3:
                removeInicio(&lista1);
                break;
            case 0:
                cout << "saindo..." << endl;
                break;
            default:
                cout << "opcao invalida! digite de novo." << endl;
        }
        
    } while(opcao != 0); // repete tudo enquanto a opção for diferente de zero
    
    return 0;
}
    