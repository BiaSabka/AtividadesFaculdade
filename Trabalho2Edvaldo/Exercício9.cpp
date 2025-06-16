/* Faça um programa que receba dois arquivos do usuário, e crie um terceiro
arquivo com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido
do conteúdo do segundo). */

#include <iostream>
#include <fstream>

using namespace std;

void copiarConteudo(ifstream &origem, ofstream &destino) {
    char caractere;
    while (origem.get(caractere)) {
        destino.put(caractere);
    }
}

int main() {
    string nomeArq1, nomeArq2, nomeSaida;

    cout << "Digite o nome do primeiro arquivo (com .txt): ";
    cin >> nomeArq1;

    cout << "Digite o nome do segundo arquivo (com .txt): ";
    cin >> nomeArq2;

    cout << "Digite o nome do arquivo de saída (com .txt): ";
    cin >> nomeSaida;

    ifstream arquivo1(nomeArq1);
    ifstream arquivo2(nomeArq2);
    ofstream arquivoSaida(nomeSaida);

    if (!arquivo1 || !arquivo2 || !arquivoSaida) {
        cout << "Erro ao abrir um dos arquivos." << endl;
        return 1;
    }

    copiarConteudo(arquivo1, arquivoSaida);
    copiarConteudo(arquivo2, arquivoSaida);

    arquivo1.close();
    arquivo2.close();
    arquivoSaida.close();

    cout << "Conteúdo dos arquivos foi unido com sucesso em '" << nomeSaida << "'.\n";

    return 0;
}