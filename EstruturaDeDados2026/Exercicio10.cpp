// faça o código de else do 'CASO B: MEIO ou no FIM' linha 141

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
    cout << "NULL" << endl;
}

void removeFim(LISTA *l){
    // Qual a primeira validação??
    // validar se a lista está vazia!!
    if (l->fim == nullptr){
        cout << "Lista vazia!!";
        return;
    }

    // criar um nó auxiliar
    no *atual = l->fim;

    // Verificar 2 situações aqui
    // 1º Se existe apenas 1 elemento
    if (atual->ant == nullptr) {
        cout << "Existe apenas 1 elemento na lista!";
        // inicializa a lista de controle
        init(l);
    } else {// 2º Se existe mais de 1 elemento
        // atualizar a lista de controle
        l->fim = atual->ant; // atualizou o novo fim
        // atualizar o PROX do novo último elemento
        l->fim->prox = nullptr;
        // atualizo o tamanho da lista
        l->tam--;
    }

    // remove o último elemento
    delete atual; // libere espaço na memória
}
// REMOVE INICIO ???
// Menu

// insere ordenado
void insereOrdenado(LISTA *l, int ch) {
    // PRIMEIRA COISA É CRIAR O NÓ!!!
    no *novo = new no;
    // insere a chave no nó
    novo->chave = ch;
    
    //CASO A: Lista Vazia ou INÍCIO
    if(l->inicio == nullptr || ch <= l->inicio->chave){
        //preenchimento básico
        novo->ant = nullptr;
        novo->prox = l->inicio;
        // verificar  se a lista tem pelo menos 1 elemento
        if (l->inicio != nullptr){
            l->inicio->ant = novo;
        } else { // não tem nenhum elemento
            // inicio e fim é o mesmo elemento, pois se entrou aqui a lista estava vazia
            l->fim = novo;
        }
     // atualizar a lista de controle
     // novo inicio
     l->inicio = novo;
     l->tam++;
    
    } else { // CASO B: MEIO ou no FIM <-- TAREFA P/ 22/05
        
        // criação do nó auxiliar que percorre a lista do inicio
        no *atual = l->inicio;
        // mudar para "atual" só quando:
        // o próximo não for nulo e a a chave do próximo for menor que a chave que queremos 
        while (atual->prox != nullptr && atual->prox->chave < ch) {
            atual = atual->prox;
        }
        // quando achar, o novo vai entrar logo depois do atual
        novo->prox = atual->prox; 
        novo->ant = atual;        

        // se n for o fim da lista, arruma a ligação de quem ficou na frente do novo
        if (atual->prox != nullptr) {
            atual->prox->ant = novo; // o da frente olha para trás e vê o novo
        } else {
            // se não tinha nenhum na frente, significa que parou no fim da lista
            l->fim = novo; // atualiza que é o novo fim
        }
        atual->prox = novo;
        l->tam++;
    }
}

int main()
{
    LISTA lista1;
    init(&lista1);
    insereFim(&lista1, 10);
    insereFim(&lista1, 20);
    insereFim(&lista1, 30);

    cout << "Lista Original:" << endl;
    imprime(&lista1);

    cout << "\nRemovendo o Fim da Lista (30), A Lista Fica:" << endl;
    removeFim(&lista1);
    imprime(&lista1);

    cout << "\nInserindo 15 (No meio), A Lista Fica:" << endl;
    insereOrdenado(&lista1, 15);
    imprime(&lista1);

    cout << "\nInserindo 25 (No fim), A Lista Fica:" << endl;
    insereOrdenado(&lista1, 25);
    imprime(&lista1);

    cout << "\nInserindo 5 (No inicio), A Lista Fica:" << endl;
    insereOrdenado(&lista1, 5);
    imprime(&lista1);

    return 0;
}