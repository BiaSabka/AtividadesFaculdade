/* 1. Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas linhas esse arquivo possui. */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string NomeArquivo;
    cout << "Digite o Nome do Arquivo (com .txt): ";
    cin >> NomeArquivo;

    ifstream Arquivo(NomeArquivo);
    if (!Arquivo) {
        cout << "Erro ao Abrir o Arquivo." << endl;
        return 1;
    }

    string linha;
    int Contador = 0;

    while (getline(Arquivo, linha)) {
        Contador++;
    }

    Arquivo.close();

    cout << "O Arquivo Possui " << Contador << " Linha(s)." << endl;

    return 0;
}