// Escreva um programa que tenha uma sub-rotina para validar a nota de um aluno. 
// Se a nota informada estiver fora do intervalo de 0 a 10, a função deve retornar falso. 
// O programa principal deve pedir uma nova entrada até que uma nota válida seja informada.
// Além disso, exiba uma mensagem para o usuário indicando se a nota foi aceita ou não.

#include <iostream>

using namespace std;

bool ValidarNota(float Nota) {
    return (Nota >= 0 && Nota <= 10);
}

int main() {
    float Nota;

    do {
        cout << "Digite uma nota entre 0 e 10: ";
        cin >> Nota;

        if (!ValidarNota(Nota)) {
            cout << "Falso! (Nota invalida) Por favor tente novamente.\n";
        }
    } while (!ValidarNota(Nota));

    cout << "Nota aceita! Ela foi: " << Nota << endl;
    cout << " \n Encerrando Programa"; 

    return 0;
}
