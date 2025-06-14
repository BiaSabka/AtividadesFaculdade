/*                          Desafio parte III:
Escrever um programa que leia um número determinado de inteiros (1.000 como máximo)
do terminal e os visualize na mesma ordem e com a condição de que se escreva somente
uma vez cada inteiro. Se o inteiro já foi impresso, não deve ser visualizado novamente.
Por exemplo, se os números seguintes são lidos do terminal 55, 78,25, 55, 24,3 e 7 o programa
deve visualizar o seguinte: 55,78,25,24,3 e 7. Deve-se trabalhar com ponteiros para tratar
com o array no qual foram armazenados os números.                                       */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n > 1000)
        n = 1000;

    int *numeros = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> *(numeros + i);
    }

    for (int i = 0; i < n; i++)
    {
        bool repetido = false;
        for (int j = 0; j < i; j++)
        {
            if (*(numeros + i) == *(numeros + j))
            {
                repetido = true;
                break;
            }
        }
        if (!repetido)
        {
            cout << *(numeros + i) << " ";
        }
    }

    cout << endl;
    delete[] numeros;
    return 0;
}