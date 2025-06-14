/*   1. Utilizando um ponteiro para acessar os campos do registro.
          a) Defina um registro Aluno com os campos nome e idade.
          b) Defina uma variável do tipo registro.
          c) Defina um ponteiro para este tipo de registro.
          d) Por meio do ponteiro atribua valores a cada campo deste registro.  */

#include <iostream>
using namespace std;

struct Aluno
{
    string nome;
    int idade;
};

int main()
{
    Aluno aluno;
    Aluno *ponteiro = &aluno;
    ponteiro->nome = "Bianca";
    ponteiro->idade = 19;
    cout << "Nome: " << ponteiro->nome << "\nIdade: " << ponteiro->idade << endl;
    return 0;
}