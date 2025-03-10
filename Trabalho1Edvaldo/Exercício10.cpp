// Faça um programa que tenha um procedimento para exibir a tabuada de um número.
// A saída deve seguir o seguinte formato:
// 1 x N =
// 2 x N =
// 3 x N =

#include <iostream>
using namespace std;

void ExibirTabuada(int N) 
{
    for (int i = 1; i <= 10; i++) 
    {
        cout << i << " x " << N << " = " << i * N << endl;
    }
}

int main() 
{
    int Numero;

    cout << "Digite um numero para ver a sua tabuada: ";
    cin >> Numero;

    ExibirTabuada(Numero);

    return 0;
}
