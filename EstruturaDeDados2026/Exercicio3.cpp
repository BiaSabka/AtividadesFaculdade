//Utilizando o código desenvolvido em aula. Criar as seguintes funções:
// 1) Buscar um elemento na lista.
//2) Remover um elemento da lista (Não é permitido "buracos" na lista").

#include <iostream>

using namespace std;

struct REGISTRO {
    int chave;
};

// função que busca um elemento
int buscar(REGISTRO lista[], int tamanho, int chave){

    // percorre toda a lista
    for(int i = 0; i < tamanho; i++){

        // verifica se encontrou o valor
        if(lista[i].chave == chave){

            // retorna a posição
            return i;
        }
    }

    // caso não encontrar
    return -1;
}


// função para remover um elemento da lista
void remover(REGISTRO lista[], int &tamanho, int chave){

    // buscamos o elemento
    int posicao = buscar(lista, tamanho, chave);

    // caso não econtrar
    if(posicao == -1){
        cout<<"Elemento nao encontrado"<<endl;
        return;
    }

    // move todos os elementos para esquerda
    for(int i = posicao; i < tamanho - 1; i++){

        lista[i] = lista[i + 1];
    }

    // e aí sim diminui o tamanho da lista
    tamanho--;

    cout<<"Elemento removido com sucesso"<<endl;
}


int main() {
    
    //declarando minha estrutura
    REGISTRO lista[10];
    int tamanho = 4;

    // preenchendo a lista
    lista[0].chave = 10;
    lista[1].chave = 20;
    lista[2].chave = 30;
    lista[3].chave = 40;

    int valor;
    
    // perguntando qual elemento o usuário quer buscar
    cout<<"Digite um valor para buscar: ";
    cin>>valor;

    // chamando a função para buscar
    int pos = buscar(lista, tamanho, valor);

    //caso não encontrar
    if(pos == -1){
        cout<<"Valor nao encontrado"<<endl;
    }
    // caso encontrar
    else{
        cout<<"Valor encontrado na posicao: "<<pos<<endl;
    }


    // perguntando ao usuário qual elemento quer remover
    cout<<"\nDigite um VALOR (nao posicao) para remover: ";
    cin>>valor;

    // chamando função para remover
    remover(lista, tamanho, valor);
 
    // mostrando a lista após a remoção e chamando a função de
    // mover os elementos 
    cout<<"\nLista depois da remocao:"<<endl;

    for(int i = 0; i < tamanho; i++){
        cout<<lista[i].chave<<endl;
    }

}