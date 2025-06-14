/*                               Desafio parte II:
   É necessário armazenar a seguinte informação de uma pessoa: nome, idade, altura
   e peso. Escrever uma função que leia os dados de uma pessoa, recebendo como
   parâmetro um ponteiro e outra função que os visualize.                          */

#include <iostream>
using namespace std;

struct Pessoa
{
    string nome;
    int idade;
    float altura;
    float peso;
};

void lerDados(Pessoa *p)
{
    cout << "Nome: ";
    cin >> p->nome;
    cout << "Idade: ";
    cin >> p->idade;
    cout << "Altura: ";
    cin >> p->altura;
    cout << "Peso: ";
    cin >> p->peso;
}

void mostrarDados(Pessoa *p)
{
    cout << "Nome: " << p->nome << endl;
    cout << "Idade: " << p->idade << endl;
    cout << "Altura: " << p->altura << endl;
    cout << "Peso: " << p->peso << endl;
}

int main()
{
    Pessoa p;
    lerDados(&p);
    mostrarDados(&p);
    return 0;
}