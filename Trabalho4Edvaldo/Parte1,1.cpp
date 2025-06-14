/*    a) Crie um programa que declare duas variáveis inteiras e use um ponteiro para
trocar seus valores.
      b) Faça o mesmo para duas variáveis do tipo float e char.                     */


#include <iostream>
using namespace std;

void TrocarInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void TrocarFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void TrocarChar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    cout << "Antes da troca (int): x = " << x << ", y = " << y << endl;
    TrocarInt(&x, &y);
    cout << "Depois da troca (int): x = " << x << ", y = " << y << endl;

    float f1 = 3.14, f2 = 1.59;
    cout << "\nAntes da troca (float): f1 = " << f1 << ", f2 = " << f2 << endl;
    TrocarFloat(&f1, &f2);
    cout << "Depois da troca (float): f1 = " << f1 << ", f2 = " << f2 << endl;

    char c1 = 'A', c2 = 'B';
    cout << "\nAntes da troca (char): c1 = " << c1 << ", c2 = " << c2 << endl;
    TrocarChar(&c1, &c2);
    cout << "Depois da troca (char): c1 = " << c1 << ", c2 = " << c2 << endl;

    return 0;
}
