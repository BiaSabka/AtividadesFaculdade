/*    3. Crie um programa que declare um vetor de inteiros com 5 posições e utilizando um
ponteiro faça:
          a) Preencha o vetor.
          b) Mostre os dados armazenados.
          c) Calcule a média dos dados armazenados.    */

#include <iostream>
using namespace std;

int main()
{
    int Vetor[5];
    int *Ponteiro = Vetor;
    int soma = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "Digite o elemento " << i + 1 << ": ";
        cin >> *(Ponteiro + i);
        soma += *(Ponteiro + i);
    }
    cout << "\n Elementos do vetor: ";
    for (int i = 0; i < 5; i++)
        cout << *(Ponteiro + i) << " ";
    cout << "\n Media dos elementos: " << soma / 5.0 << endl;
    return 0;
}
