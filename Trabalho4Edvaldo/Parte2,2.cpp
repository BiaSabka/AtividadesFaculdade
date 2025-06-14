/*   2. Modifique o exercício anterior para receber os dados de 3 alunos (Vetor de registros)
e fazer toda a manipulação dos registros por meio de um ponteiro.
        a) Preencher todos os registros
        b) Mostrar o conteúdo.   */

#include <iostream>
using namespace std;

struct Aluno
{
    string nome;
    int idade;
};

int main()
{
    Aluno alunos[3];
    Aluno *Ponteiro = alunos;

    for (int i = 0; i < 3; i++)
    {
        cout << "Nome: ";
        cin >> Ponteiro[i].nome;
        cout << "Idade: ";
        cin >> Ponteiro[i].idade;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Aluno " << i + 1 << ": " << Ponteiro[i].nome << ", " << Ponteiro[i].idade << " anos" << endl;
    }

    return 0;
}