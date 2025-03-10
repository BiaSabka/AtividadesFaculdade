// Crie um programa que contenha uma sub-rotina para validar a entrada de caracteres.
// Somente as letras “A”, “a”, “P” ou “p” são permitidas.
// Caso o usuário informe um caractere diferente, a função deve retornar falso e solicitar uma nova entrada.
// Informe ao usuário se o caractere foi aceito ou não.

#include <iostream>

using namespace std;

bool ValidarCaractere(char Caractere)
{
    return (Caractere == 'A' || Caractere == 'a' || Caractere == 'P' || Caractere == 'p');
}

int main()
{
    char Letra;

    do
    {
        cout << "Digite Um Dos Seguintes Caracteres: A, a, P, p ";
        cout << "\n Resposta: ";
        cin >> Letra;

        if (!ValidarCaractere(Letra))
        {
            cout << "Falso! (Caractere invalido) Por favor tente novamente.\n";
        }
        else
        {
          cout << "\n Caractere aceito! Ele foi: " << Letra << endl;
          cout << " \n Encerrando Programa";
          return 0;
        }
        
    } while (true);

}