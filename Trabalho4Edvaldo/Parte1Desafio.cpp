/*                                     Desafio parte I:
    Escrever um programa para gerar uma matriz de 4 x 5 números reais, multiplicar a primeira
    coluna por qualquer outra da matriz e mostrar a soma dos produtos. O programa deve ser
    decomposto em subprogramas e utilizar ponteiros para acessar os elementos da matriz.    */

#include <iostream>
using namespace std;

void PreencherMatriz(float (*Matriz)[5])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
        {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(*(Matriz + i) + j);
        }
}

float MultiplicarColunas(float (*Matriz)[5], int col2)
{
    float Soma = 0;
    for (int i = 0; i < 4; i++)
        Soma += *(*(Matriz + i)) * *(*(Matriz + i) + (col2 - 1));
    return Soma;
}

int main()
{
    float Matriz[4][5];
    int col2;
    PreencherMatriz(Matriz);
    cout << "\nEscolha a segunda coluna para multiplicar (2-5): ";
    cin >> col2;
    cout << "\nSoma dos produtos: " << MultiplicarColunas(Matriz, col2) << endl;
    return 0;
}