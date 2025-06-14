/*   3. Desenvolva um programa que crie um registro Pessoa com nome
        (string/vetor de caracteres) e cpf (inteiro).
      a) Use new() para alocar dinamicamente uma variável para cadastrar uma
           pessoa.
      b) Leia e exiba os dados desta pessoa.
      c) Após o uso libere a memória por meio do operador delete().   */

#include <iostream>
using namespace std;

struct Pessoa
{
    char nome[100];
    int cpf;
};

int main()
{
    Pessoa *p = new Pessoa;

    cin.getline(p->nome, 100);
    cin >> p->cpf;

    cout << "Nome: " << p->nome << endl;
    cout << "CPF: " << p->cpf << endl;

    delete p;
    return 0;
}