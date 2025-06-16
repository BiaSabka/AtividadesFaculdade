/* Faça um programa que leia o conteúdo de um arquivo e crie um arquivo com o
mesmo conteúdo, mas com todas as letras minúsculas convertidas para maiúsculas.
Os nomes dos arquivos serão fornecidos, via teclado, pelo usuário. A função que
converte maiúscula para minúscula é o toupper(). Ela é aplicada em cada caractere
da string. */

#include <iostream>
#include <fstream>
#include <cctype> 

using namespace std;

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
        saida.put(toupper(caractere));
    }

    entrada.close();
    saida.close();

    cout << "Arquivo '" << nomeSaida << "' criado com todas as letras em maiúsculas.\n";

    return 0;
}