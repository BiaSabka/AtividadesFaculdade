// Escreva um programa com um procedimento que receba três notas e uma letra como parâmetros.
//  Se a letra for “A”, calcule e retorne a média aritmética.
// Se for “P”, retorne a média ponderada considerando os pesos 2, 3 e 4 para as respectivas notas.

#include <iostream>

using namespace std;

bool ValidarCaractere(char Caractere)
{
    return (Caractere == 'A' || Caractere == 'P');
}

void ContaMediaAritmetica(float Nota1, float Nota2, float Nota3)
{
    float Media = (Nota1 + Nota2 + Nota3) / 3;
    cout << "A Media Aritmetica das notas foi: " << Media << endl;
}

void ContaMediaPonderadaComPesos(float Nota1, float Nota2, float Nota3)
{
    float MediaPonderada = (2 * Nota1 + 3 * Nota2 + 4 * Nota3) / 9;
    cout << "A Media Ponderada das notas foi: " << MediaPonderada << endl;
}


int main()
{
    float Nota1, Nota2, Nota3;
    char Caractere;

    do
    {
        cout << "\nDigite o Valor que Deseja para a Primeira Nota \n";
        cout << "Resposta: ";
        cin >> Nota1;
        cout << "\nDigite o Valor que Deseja para a Segunda Nota \n";
        cout << "Resposta: ";
        cin >> Nota2;
        cout << "\nDigite o Valor que Deseja para a Terceira Nota \n";
        cout << "Resposta: ";
        cin >> Nota3;

        cout << "\n Agora, Se quer saber a media aritmetica digite 'A', ou a media ponderada digite 'P': ";
        cin >> Caractere;

        if (ValidarCaractere(Caractere))
        {
            cout << "Caractere aceito!Calculando...\n";
            if (Caractere == 'A')
            {
                ContaMediaAritmetica(Nota1, Nota2, Nota3);
                break;
            }
            if (Caractere == 'P')
            {
                ContaMediaPonderadaComPesos(Nota1, Nota2, Nota3);
                break;
            }
        }
        else
        {
            cout << "Caractere Invalido, por favor tente novamente\n";
        }
    } while (true);

    return 0;
}