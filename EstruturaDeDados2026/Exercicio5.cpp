// Implemente um Menu e Faça Validações de Inserção e Remoção.

#include <iostream>

using namespace std;
#define MAX 6

// fila circular (alocação estática)
// se precisar modificar o tipo da variável
typedef int TIPOCHAVE;

// cria a estrutura
typedef struct{
    TIPOCHAVE chave;
    //nome
    //cpf
    //idade
}REGISTRO;

// cria a fila
typedef struct{
    REGISTRO A[MAX];
    // variáveis de controle
    // marcar a posição inicial
    int ini;
    // quantidade de elemtentos
    int qtd;
}FILA;

// Funções necessárias
//1 - Inicializar
//2 - retornar a quantidade de elemtentos
//3 - imprimir a fila
//4 - inserir um elemento na fila (no final)
//5 - remover um elemento na fila (início)
//6 - reiniciar a fila

// 1. passa por referência
void init(FILA *f);
// 2. retornar qtd
int qtdElem(FILA *f);
// 3. imprime
void imprimir(FILA *f);
// 4. insere
bool insereFila(FILA *f, REGISTRO reg);
// 5. remover
bool removeFila(FILA *f);


int main()
{
    REGISTRO aux; // auxiliar para inserir
    bool r; // resposta dos métodos

    FILA f; // criação da nossa fila

    // iniciar a manipulação
    init(&f);

    //inserir elementos
    aux.chave=10;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso
    if(r) cout << "Inserido: " << aux.chave << endl;
    // avisar caso não tenha inserido
    else cout << "erro ao inserir" << endl;

    aux.chave=20;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso
    if(r) cout << "Inserido: " << aux.chave << endl;
    // avisar caso não tenha inserido
    else cout << "Erro ao inserir!" << endl;

    aux.chave=30;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso
    if(r) cout << "inserido: " << aux.chave << endl;
    // avisar caso não tenha inserido
    else cout << "erro ao inserir" << endl;

    aux.chave=40;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso
    if(r) cout << "inserido: " << aux.chave << endl;
    // avisar caso não tenha inserido
    else cout << "erro ao inserir" << endl;
    
    imprimir(&f);

    removeFila(&f);
    imprimir(&f);

    aux.chave=50;
    r = insereFila(&f, aux);

    imprimir(&f);
    
    // Menu 
    int opcao = -1; // variável para controlar a escolha
    while(opcao != 0){ // enquanto nao escolher sair
        cout << "\n--- MENU DA FILA CIRCULAR ---" << endl;
        cout << "1 - Inserir elemento" << endl;
        cout << "2 - Remover elemento" << endl;
        cout << "3 - Imprimir fila" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";
        cin >> opcao; // lê a opção do usuário

        // validações de inserção e remoção
        if(opcao == 1){ // caso o usuário queira inserir
            cout << "Digite o valor da chave: ";
            cin >> aux.chave; // lê o valor novo
            r = insereFila(&f, aux); // tenta inserir
            if(r){ // se retornar verdadeiro
                cout << "Sucesso: Elemento inserido!" << endl;
            } else { // se retornar falso (fila cheia)
                cout << "Erro: A fila esta cheia!" << endl;
            }
        } 
        else if(opcao == 2){ // caso queira remover
            r = removeFila(&f); // tenta remover
            if(r){ // se retornar verdadeiro
                cout << "Sucesso: Elemento removido!" << endl;
            } else { // se retornar falso (fila vazia)
                cout << "Erro: A fila esta vazia!" << endl;
            }
        }
        else if(opcao == 3){ // imprimir
        cout << "Fila Atual: "<< endl;
            imprimir(&f);
        }
    }
}

// 1. passa por referência
void init(FILA *f){
    // inicializa a nossa fila
    f->ini = 0; // inicio na posição 0
    f->qtd = 0; // possui 0 elementos
}
// 2. retornar qtd
int qtdElem(FILA *f){
    // retorno quantos elementos a fila possui
    return f->qtd;
}
// 3. impressão
void imprimir(FILA *f){
    // preciso de um for para percorrer o vetor
    //(quantidade de elementos)
    // e precisamos saber a ordem de impressão

    // pegar a posição inicial
    int i = f->ini; // controla o inicio
    int j;
    for(j=0; j < f->qtd; j++){
        cout << f->A[i].chave << " ";
        // pulo do gato
        i = (i + 1) % MAX;
    }
    cout<<endl;
}
// 4. insere
bool insereFila(FILA *f, REGISTRO reg){
    // REGRAS ANTES DE INSERIR
    // - se estiver cheia
    // - atualiza a quantidade de elementos
    if (f->qtd >= MAX)
        return false;
    // calcula a posição para inserir
    int pos = (f->ini + f->qtd) % MAX;
    // insere o elemento
    f->A[pos] = reg;
    // atualiza a quantidade de elementos
    f->qtd++;
    return true;
}
// 5. remover
bool removeFila(FILA *f){
    // preciso verificar para remover??
    // - exclui os primeiros elementos
    // - se existem elementos??
    // ----- removeu:
    // - atualizar a quantidade de elementos
    // - atualiza qual é o início

    if (f->qtd == 0) // a fila é vazia??
        return false;

    // calcular o início
    f->ini = (f->ini + 1) % MAX;
    f->qtd--;
    return true;
}