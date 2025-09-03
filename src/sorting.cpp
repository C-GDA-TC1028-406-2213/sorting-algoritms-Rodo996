#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace SortingAlgorithms {

void bubbleSort(int arr[], int n) {
    // Bucle externo para pasadas
    for (int i = 0; i < n-1; ++i) {
        // Bucle interno para comparar elementos adyacentes
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                // Intercambiar
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int n) {
    for (int i = 0; i < n-1; ++i) {
        // Bucle interno para comparar elementos adyacentes
        for (int j = 0; j < n-i-1; ++j) {
            if (array[j] > array[j+1]) {
                int tallest = array[j];
                // Intercambiar
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                //tallest = array[-1];

            }
        }
    }
}

void insertionSort(int arr[], int n) {
    
}

void merge(int arr[], int l, int m, int r) {
    // Calculamos el tamaño de los dos subarrays que vamos a fusionar
    int n1 = m - l + 1;  // Tamaño del subarray izquierdo [l...m]
    int n2 = r - m;      // Tamaño del subarray derecho [m+1...r]
    
    // Creamos arrays temporales para almacenar los subarrays
    int L[n1], R[n2];
    
    // Copiamos los datos del subarray izquierdo al array temporal L[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    // Copiamos los datos del subarray derecho al array temporal R[]
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Inicializamos los índices para fusionar los arrays
    int i = 0;    // Índice inicial del primer subarray
    int j = 0;    // Índice inicial del segundo subarray
    int k = l;    // Índice inicial del subarray fusionado
    
    // Fusionamos los dos arrays temporales de vuelta al array original
    // Comparamos elementos y colocamos el menor en la posición correcta
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Elemento del array izquierdo es menor o igual
            i++;
        } else {
            arr[k] = R[j];  // Elemento del array derecho es menor
            j++;
        }
        k++;  // Avanzamos al siguiente índice del array fusionado
    }
    
    // Copiamos los elementos restantes del array izquierdo L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copiamos los elementos restantes del array derecho R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
     // Condición base: si l >= r, el subarray tiene 1 elemento o menos
    // Por lo tanto, ya está "ordenado" y no necesitamos hacer nada
    if (l >= r) {
        return;
    }
    
    // Calculamos el punto medio para dividir el array en dos partes
    // Usamos esta fórmula para evitar desbordamiento en arrays grandes
    int m = l + (r - l) / 2;
    
    // Llamada recursiva: ordenamos la mitad izquierda [l...m]
    mergeSort(arr, l, m);
    
    // Llamada recursiva: ordenamos la mitad derecha [m+1...r]
    mergeSort(arr, m + 1, r);
    
    // Fusionamos las dos mitades ya ordenadas
    merge(arr, l, m, r);
}

int partition(int arr[], int low, int high) {
     // Elegimos el último elemento como pivot
    int pivot = arr[high];
    
    // Índice del elemento más pequeño, indica la posición correcta
    // del pivot encontrado hasta ahora
    int i = (low - 1);
    
    // Recorremos todos los elementos excepto el pivot
    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual al pivot
        if (arr[j] <= pivot) {
            i++; // Incrementamos el índice del elemento menor
            
            // Intercambiamos arr[i] y arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    // Colocamos el pivot en su posición correcta
    // Intercambiamos arr[i+1] y arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    // Retornamos la posición del pivot
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    // Condición base: si low < high, aún hay elementos que ordenar
    if (low < high) {
        // Particionar el array y obtener el índice del pivot
        // Después de partition(), el pivot estará en su posición final
        int pivotIndex = partition(arr, low, high);
        
        // Recursivamente ordenar los elementos antes del pivot
        // (elementos menores)
        quickSort(arr, low, pivotIndex - 1);
        
        // Recursivamente ordenar los elementos después del pivot
        // (elementos mayores)
        quickSort(arr, pivotIndex + 1, high);
    }
    // Si low >= high, significa que hay 1 o 0 elementos, ya está ordenado
}

void heapify(int arr[], int n, int i) {
    
}

void heapSort(int arr[], int n) {
    
}

void printArray(int arr[], int n) {
    if (n == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void SortingTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void SortingTimer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}

double SortingTimer::getElapsedMilliseconds() const {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count() / 1000.0;
}

std::string SortingTimer::getElapsedTime() const {
    double ms = getElapsedMilliseconds();
    std::stringstream ss;
    
    if (ms < 1.0) {
        ss << std::fixed << std::setprecision(3) << (ms * 1000) << " microseconds";
    } else if (ms < 1000.0) {
        ss << std::fixed << std::setprecision(3) << ms << " ms";
    } else {
        ss << std::fixed << std::setprecision(3) << (ms / 1000.0) << " seconds";
    }
    
    return ss.str();
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr = generateSortedArray(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    for (int i = 0; i < swaps && i < size/2; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

}