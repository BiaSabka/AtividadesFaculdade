// Resolva o exercício anterior utilizando as sub-rotinas criadas nos exercícios 1 e 2 
// para validar as notas e a entrada da letra.

#include <iostream>

using namespace std;

bool ValidarCaractere(char Caractere)
{
    return (Caractere == 'A' || Caractere == 'P');
}

bool ValidarNota(float Nota)
{
    return (Nota >= 0.0 && Nota <= 10.0);
}

void ContaMediaAritmetica(float Nota1, float Nota2, float Nota3)
{
    float Media = (Nota1 + Nota2 + Nota3) / 3;
    cout << "A media das notas foi: " << Media << endl;
}

void ContaMediaPonderadaComPesos(float Nota1, float Nota2, float Nota3)
{
    float MediaPonderada = (2 * Nota1 + 3 * Nota2 + 4 * Nota3) / 9;
    cout << "A media ponderada das notas foi: " << MediaPonderada << endl;
}

int main()
{
    float Nota1, Nota2, Nota3;
    char Caractere;
    bool EntradaValida = false;

    while (!EntradaValida)
    {
        cout << "\nDigite o Valor que Deseja para a Primeira Nota (entre 0 e 10) \n";
        cout << "Resposta: ";
        cin >> Nota1;
        cout << "\nDigite o Valor que Deseja para a Segunda Nota (entre 0 e 10)\n";
        cout << "Resposta: ";
        cin >> Nota2;
        cout << "\nDigite o Valor que Deseja para a Terceira Nota (entre 0 e 10)\n";
        cout << "Resposta: ";
        cin >> Nota3;

        if (ValidarNota(Nota1) && ValidarNota(Nota2) && ValidarNota(Nota3))
        {
            EntradaValida = true;
        }
        else
        {
            cout << "Uma ou mais notas sao invalidas! Tente novamente.\n";
        }
    }

    EntradaValida = false;

    while (!EntradaValida)
    {
        cout << "\n Agora, Se quer saber a media aritmetica digite 'A', ou a media ponderada digite 'P': ";
        cin >> Caractere;

        if (ValidarCaractere(Caractere))
        {
            EntradaValida = true;
        }
        else
        {
            cout << "Caractere invalido! Por Favor,Tente novamente.\n";
        }
    }

    if (Caractere == 'A')
    {
        ContaMediaAritmetica(Nota1, Nota2, Nota3);
    }
    else
    {
        ContaMediaPonderadaComPesos(Nota1, Nota2, Nota3);
    }

    return 0;
}