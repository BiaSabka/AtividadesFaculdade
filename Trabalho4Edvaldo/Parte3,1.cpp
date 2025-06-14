/*   1. Utilize o operador new() para alocar um bloco com 5 números inteiros.
       a) Preencha este bloco com valores inteiros.
       b) Mostre os dados preenchidos.
       c) Após o uso libere a memória por meio do operador delete().    */

#include <iostream>
using namespace std;

int main()
{
    int *Numeros = new int[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> Numeros[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << Numeros[i] << " ";
    }
    cout << endl;

    delete[] Numeros;
    return 0;
}