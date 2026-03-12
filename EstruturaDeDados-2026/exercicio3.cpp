#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz lida:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar memória
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}