/* Faça um programa que receba do usuário um arquivo texto e mostre na tela
quantas vezes cada letra do alfabeto aparece dentro do arquivo. */

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

    int Letras[26] = {0};

    char c;
    while (Arquivo.get(c)) {
        if (isalpha(c)) {
            c = tolower(c); 
            Letras[c - 'a']++;
        }
    }

    Arquivo.close();

    cout << "\nQuantidade de Cada Letra:\n";
    for (int i = 0; i < 26; i++) {
        char Letra = 'a' + i;
        cout << Letra << ": " << Letras[i] << endl;
    }

    return 0;
}