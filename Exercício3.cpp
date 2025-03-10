// Faça um programa que tenha uma sub-rotina que receba dois números inteiros. 
// A sub-rotina deve calcular e exibir a soma dos dois números, 
// além da subtração e da divisão do maior pelo menor. 
// Certifique-se de que os números informados não sejam iguais.

#include <iostream>

using namespace std;

bool ValidarNumeros(float Numero1, float Numero2)
{
    return (Numero1 != Numero2);
}

void Contas(float Numero1, float Numero2)
{
    float Soma, Subtracao;
    float Divisao;

    Soma = Numero1 + Numero2;

    if ( Numero1 > Numero2)
    {
        Subtracao = Numero1 - Numero2;
        Divisao = Numero1 / Numero2;
    }
    else
    {
        Subtracao = Numero2 - Numero1;
        Divisao = Numero2 / Numero1;
    }

    cout << "Soma: \n"
         << Soma << endl;
    cout << "Subtracao: \n"
         << Subtracao << endl;
    cout << "Divisao: \n" << Divisao << endl;

    cout << "Encerrando Programa...";


}

int main()
{
    float Numero1, Numero2;
    do
    {
        cout << "Digite o Primeiro Numero: \n";
        cin >> Numero1;

        cout << "Digite o Segundo Numero: \n";
        cin >> Numero2;

        if (!ValidarNumeros(Numero1, Numero2))
        {
            cout << "Sinto Muito, nao aceitamos numeros iguais, tente novamente \n" << endl;
        }

    } while (!ValidarNumeros(Numero1, Numero2));

    Contas(Numero1, Numero2);

    return 0;
}