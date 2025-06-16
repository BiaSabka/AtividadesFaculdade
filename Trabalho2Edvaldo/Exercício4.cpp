/* Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas letras são vogais e quantas são consoantes. */

#include <iostream>
#include <fstream>
#include <cctype> 

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

    char Caractere;
    int Vogais = 0, Consoantes = 0;

    while (Arquivo.get(Caractere)) {
        if (isalpha(Caractere)) { 
            char c = tolower(Caractere); 
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                Vogais++;
            } else {
                Consoantes++;
            }
        }
    }

    Arquivo.close();

    cout << "Vogais: " << Vogais << endl;
    cout << "Consoantes: " << Consoantes << endl;

    return 0;
}