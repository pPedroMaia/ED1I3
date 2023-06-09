#include <iostream>
using namespace std;

void troca(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int particao(int* v, int menor, int maior) {
    int pivo = v[maior];
    int i = menor - 1;

    for (int j = menor; j <= maior - 1; j++) {
        if (v[j] < pivo) {
            i++;
            troca(v[i], v[j]);
        }
    }

    troca(v[i + 1], v[maior]);
    return i + 1;
}

void quickSort(int* v, int menor, int maior) {
    if (menor < maior) {
        int pivoIndex = particao(v, menor, maior);

        quickSort(v, menor, pivoIndex - 1);
        quickSort(v, pivoIndex + 1, maior);
    }
}

int main() {
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    int n = sizeof(v) / sizeof(v[0]);

    cout << "Vetor antes da ordenacao: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    quickSort(v, 0, n - 1);

    cout << "Vetor depois da ordenacao: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
