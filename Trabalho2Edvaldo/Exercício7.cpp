/* Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo
texto contendo o texto do arquivo de entrada, mas com as vogais substituídas por
'*' */

#include <iostream>
#include <fstream>
#include <cctype> 

using namespace std;

bool ehVogal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string nomeEntrada, nomeSaida;
    
    cout << "Digite o nome do arquivo de entrada (com .txt): ";
    cin >> nomeEntrada;

    cout << "Digite o nome do arquivo de saída (com .txt): ";
    cin >> nomeSaida;

    ifstream entrada(nomeEntrada);
    ofstream saida(nomeSaida);

    if (!entrada || !saida) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    char caractere;
    while (entrada.get(caractere)) {
        if (ehVogal(caractere)) {
            saida.put('*');
        } else {
            saida.put(caractere);
        }
    }

    entrada.close();
    saida.close();

    cout << "Arquivo '" << nomeSaida << "' criado com sucesso substituindo as vogais por '*'.\n";

    return 0;
}