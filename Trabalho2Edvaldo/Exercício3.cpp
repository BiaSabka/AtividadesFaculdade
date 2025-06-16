/* Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas letras são vogais. */

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
    int ContadorVogais = 0;

    while (Arquivo.get(Caractere)) { 
        char c = tolower(Caractere); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ContadorVogais++;
        }
    }

    Arquivo.close(); 

    cout << "O Arquivo Possui " << ContadorVogais << " Vogal(is)." << endl;

    return 0;
}