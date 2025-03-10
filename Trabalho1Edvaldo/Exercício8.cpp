#include <iostream>
using namespace std;

bool AnoBissexto(int Ano) {
    if (Ano % 4 == 0) {
        if (Ano % 100 == 0) {
            if (Ano % 400 == 0)
                return true;
            else
                return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int calcularIdadeEmDias(int Anos, int Meses, int Dias) {
    int TotalDias = 0;

    for (int i = 1; i <= Anos; i++) {
        if (AnoBissexto(i)) {
            TotalDias += 366;  
        } else {
            TotalDias += 365;  
        }
    }
  
    TotalDias += Meses * 30.42;  
    TotalDias += Dias;
  
    return TotalDias;
}

int main() {
    int Anos, Meses, Dias;

    cout << "\n Digite a sua idade em anos: ";
    cout << "\nResposta: ";
    cin >> Anos;
    cout << "\n Digite a sua idade em meses: ";
    cout << "\nResposta: ";
    cin >> Meses;
    cout << "\n Digite a sua idade em dias: ";
    cout << "\nResposta: ";
    cin >> Dias;
  
    int TotalDias = calcularIdadeEmDias(Anos, Meses, Dias);
  
    cout << "A sua idade total em dias é: " << TotalDias << " dias." << endl;

    return 0;
}
