// 1- Desenvolva uma função recursiva em C++ que receba um número inteiro n e retorne o seu fatorial. 

// 2- Escreva um programa que utilize uma função recursiva para calcular a soma de todos os elementos 
//    de um vetor de inteiros com 10 posições. 

#include <iostream>

using namespace std;

// função recursiva para calcular o fatorial de um número inteiro n
int fatorial(int n) {
    if (n < 0) {
        cout << "Fatorial Nao eh Definido para Numeros Negativos!" << endl;
        return -1;
    }
    else if (n == 0 || n == 1) {
        return 1; // o fatorial de 0 e 1 é 1
    }
    else {
        return n * fatorial(n - 1); // chamada recursiva
    }
}

// função recursiva para calcular a soma de todos os elementos de um vetor de inteiros
int somaVetor(int vetor[], int tamanho) {
    if (tamanho <= 0) {
        return 0; // caso base: soma de um vetor vazio é 0
    }
    else {
        return vetor[tamanho - 1] + somaVetor(vetor, tamanho - 1); // chamada recursiva
    }
}   

int main() {
    // testando o exercício 1 (Fatorial de 5 = (5 . 4 . 3 . 2 . 1) = 120)
    int numero = 5;
    cout << "Fatorial de " << numero << " e: " << fatorial(numero) << endl;

    // testando o exercício 2 (Vetor com 10 posições, de 1 a 10)
    int meuVetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "A Soma de Todos os Elementos do Vetor eh: " << somaVetor(meuVetor, 10) << endl;

    return 0;
}