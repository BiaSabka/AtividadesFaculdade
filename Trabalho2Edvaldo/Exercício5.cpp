/* Faça um programa que receba do usuário um arquivo texto e um caractere.
Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo. */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string NomeArquivo;
    char CaractereBuscado;
    int Contador = 0;

    cout << "Digite o Nome do Arquivo (com .txt): ";
    cin >> NomeArquivo;

    cout << "Digite o Caractere a ser Contado: ";
    cin >> CaractereBuscado;

    ifstream Arquivo(NomeArquivo);
    if (!Arquivo) {
        cout << "Erro ao Abrir o Arquivo." << endl;
        return 1;
    }

    char CaractereLido;
    while (Arquivo.get(CaractereLido)) {
        if (CaractereLido == CaractereBuscado) {
            Contador++;
        }
    }

    Arquivo.close();

    cout << "O caractere '" << CaractereBuscado << "' Aparece " << Contador << " Vez(es) no Arquivo." << endl;

    return 0;
}