#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um array de inteiros aleatórios
void gerarArrayAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Números aleatórios entre 0 e 99.999
    }
}

// Implementação do algoritmo Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // Índice do menor elemento encontrado
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Troca o elemento mínimo encontrado com o primeiro elemento não ordenado
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Implementação do algoritmo Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elementos do arr[0..i-1] que são maiores que o 'key' para uma posição à frente
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para medir e exibir o tempo de execução de um algoritmo de ordenação
void medirTempo(void (*sortFunc)(int[], int), int arr[], int n, const char* nomeAlgoritmo) {
    clock_t inicio, fim;
    double tempo_cpu;

    // Copia o array original para evitar alterações ao usar o mesmo conjunto de dados
    int* copia = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copia[i] = arr[i];
    }

    inicio = clock();
    sortFunc(copia, n);
    fim = clock();

    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("%s - Tempo de execução para %d elementos: %f segundos\n", nomeAlgoritmo, n, tempo_cpu);

    free(copia);
}

int main() {
    // Define tamanhos dos arrays para teste
    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int numTestes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    // Executa testes para cada tamanho de array
    for (int i = 0; i < numTestes; i++) {
        int n = tamanhos[i];
        int* arr = (int*)malloc(n * sizeof(int));
        
        gerarArrayAleatorio(arr, n);

        // Testa e mede o tempo de execução do Selection Sort
        medirTempo(selectionSort, arr, n, "Selection Sort");

        // Testa e mede o tempo de execução do Insertion Sort
        medirTempo(insertionSort, arr, n, "Insertion Sort");

        free(arr); // Libera a memória alocada para o array
    }

    return 0;
}