//Vilcapaza Choque William Vladimir
#include <iostream>
using namespace std;

void countingSort(int lista[], int size) {

  // Su tamaño se proporciona de forma estática.
  int salida[60];
  int contar[60];
  int max = lista[0];

  // Encuentra el elemento más grande del array
  for (int i = 1; i < size; i++) {
    if (lista[i] > max)
      max = lista[i];
  }

  // Inicializa el array de conteo con todos ceros.
  for (int i = 0; i <= max; ++i) {
    contar[i] = 0;
  }

  // Almacenar el conteo de cada elemento
  for (int i = 0; i < size; i++) {
    contar[lista[i]]++;
  }

  // Almacenar el recuento acumulativo de cada array
  for (int i = 1; i <= max; i++) {
    contar[i] += contar[i - 1];
  }

  // Encuentra el índice de cada elemento del array original en la array de conteo, y
  // coloca los elementos en la array de salida
  for (int i = size - 1; i >= 0; i--) {
    salida[contar[lista[i]] - 1] = lista[i];
    contar[lista[i]]--;
  }

  // Copia los elementos ordenados en el array original
  for (int i = 0; i < size; i++) {
    lista[i] = salida[i];
  }
}

// Funcion de imprimir
void imprimirArray(int lista[], int size) {
  for (int i = 0; i < size; i++)
    cout << lista[i] << " ";
  cout << endl;
}

int main() {
  int lista[] = {4, 5, 2, 8, 7, 3, 1,50};
  int n = sizeof(lista) / sizeof(lista[0]);
  countingSort(lista, n);
  imprimirArray(lista, n);
}
