#include <iostream>
using namespace std;

int CalcularFatorial(int n) 
{
    int Fatorial = 1;  

    for (int i = 1; i <= n; i++)  
    {
        Fatorial = Fatorial * i;  
    }

    return Fatorial; 
}

int main() 
{
    int Numero;

    cout << "Digite um numero inteiro: ";
    cin >> Numero;

    if (Numero < 0) 
    {
        cout << "Fatorial não e definido para numeros negativos." << endl;
    } else 
    {
        int Resultado = CalcularFatorial(Numero);
        cout << "O fatorial de " << Numero << " e: " << Resultado << endl;
    }

    return 0;
}
