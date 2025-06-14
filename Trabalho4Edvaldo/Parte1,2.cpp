/*   2. Crie um programa que leia um número inteiro e imprima:
         a) O valor digitado.
         b) O endereço da memória.
         c) O conteúdo da memória apontado pelo ponteiro.   */

#include <iostream>
using namespace std;

int main() {
    int Numero;
    int *Ponteiro;
    cout << "Digite um numero inteiro: ";
    cin >> Numero;
    Ponteiro = &Numero;
    cout << "\nValor digitado: " << Numero << endl;
    cout << "Endereco da memoria: " << Ponteiro << endl;
    cout << "Conteudo apontado pelo ponteiro: " << *Ponteiro << endl;
    return 0;
}