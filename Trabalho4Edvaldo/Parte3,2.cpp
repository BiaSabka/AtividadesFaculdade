/*   2. Desenvolva um programa que :
        a) Peça ao usuário quantos números deseja armazenar.
        b) Aloque dinamicamente por meio do operador new().
        c) Preencha toda a estrutura.
        d) Apresente o maior valor armazenado.
        e) Após o uso libere a memória por meio do operador delete().   */

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *Numeros = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> Numeros[i];
    }

    int maior = Numeros[0];
    for (int i = 1; i < n; i++)
    {
        if (Numeros[i] > maior)
        {
            maior = Numeros[i];
        }
    }

    cout << "Maior valor: " << maior << endl;

    delete[] Numeros;
    return 0;
}