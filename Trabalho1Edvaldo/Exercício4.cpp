// Desenvolva um programa que contenha uma função para calcular o volume de uma esfera.
// O raio da esfera deve ser passado como parâmetro, e a função deve retornar o volume correspondente.

#include <iostream>
#include <cmath> // Pelo que entendi é uma biblioteca que calcula valor de Pi e raio ( pow() e M_PI )

using namespace std;

double CalculoVolumeEsfera(double Raio) {
    return (4.0 / 3.0) * M_PI * pow(Raio, 3);
}

int main() {
    double Raio;

    cout << "Digite o raio da esfera que deseja: \n";
    cin >> Raio;

    double volume = CalculoVolumeEsfera(Raio);

    cout << "O volume da esfera e: \n" << volume << endl;

    return 0;
}
