/* 1. Escreva um programa que:
     a) Crie/abra um arquivo texto de nome &quot;arq.txt&quot;
     b) Permita que o usuário grave diversos caracteres nesse arquivo,
        até que o  usuário entre com o caractere &#39;0&#39;
     c) Feche o arquivo.
Por fim, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os
caracteres armazenados. */


#include <iostream>
using namespace std;

int main() 
{
    system("cls");

    FILE *Arquivo;
    char Caractere;

    Arquivo = fopen("arq.txt", "w");
    if (Arquivo == NULL) {
        cout << "\nErro ao abrir o arquivo." << endl;
        return 1;
    }

    cout << "\nDigite Caracteres que Deseja Gravar no Arquivo (Digite '0' Quando Quiser Parar):" << endl;
    while (true) {
        cin >> Caractere;
        if (Caractere == '0') {  
            break;
        }
        fputc(Caractere, Arquivo);
    }
    fclose(Arquivo);
    cout << "\nArquivo Gravado com Sucesso!" << endl;

    Arquivo = fopen("arq.txt", "r");
    if (Arquivo == NULL) {
        cout << "\nErro ao Abrir o Arquivo para Leitura." << endl;
        return 1;
    }

    cout << "\nConteudo do Arquivo:" << endl;
    while ((Caractere = fgetc(Arquivo)) != EOF) {
        cout << Caractere << endl;
    }
    fclose(Arquivo);
    
    return 0;
}
