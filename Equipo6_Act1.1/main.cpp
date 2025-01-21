#include <iostream>
#include <vector>
using namespace std;

// Función para fusionar dos subarreglos
void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1), R(n2);

    // Copiar datos a subarreglos temporales
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Fusionar los subarreglos
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {  // Orden descendente
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copiar los elementos restantes
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Función recursiva para ordenar con MergeSort
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Dividir y conquistar
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fusionar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Ingrese el numero de valores a ordenar: ";
    cin >> N;

    vector<double> arr(N);
    cout << "Ingrese " << N << " valores (reales o enteros), uno por linea:\n";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Ordenar usando MergeSort
    mergeSort(arr, 0, N - 1);

    // Imprimir los resultados
    cout << "Valores ordenados de mayor a menor: \n";
    for (const auto& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
