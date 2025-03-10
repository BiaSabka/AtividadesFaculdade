// Implemente um programa que tenha uma função para verificar se um número é primo. 
// A função deve retornar verdadeiro se o número for primo e falso caso contrário.

#include <iostream>

using namespace std;

bool Primos(int Numero)
{
    if (Numero < 2)  
        return false; 
    for (int i = 2; i * i <= Numero; i++) 
    {
        if (Numero % i == 0) 
            return false; 
    }
    
    return true; 
}

int main()
{
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;

    if (Primos(numero))
        cout << numero << " e um numero primo.\n";
    else
        cout << numero << " nao e um numero primo.\n";

    return 0;
}