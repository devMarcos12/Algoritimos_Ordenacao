#include <stdio.h>
#include <time.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    int tamanho = fim - inicio + 1;
    int temp[tamanho];
    int i = inicio, j = meio + 1, k = 0;

    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = vetor[i++];
    }

    while (j <= fim) {
        temp[k++] = vetor[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        vetor[i] = temp[k];
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void printArray(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor1[] = {12, 3, 4, 13, 9, 2, 6, 11, 5, 1, 8, 7, 10};
    int vetor2[] = {12, 3, 4, 13, 9, 2, 6, 11, 5, 1, 8, 7, 10};
    int tamanho = sizeof(vetor1) / sizeof(vetor1[0]);

    printf("Sequência original: ");
    printArray(vetor1, tamanho);

    // Teste de desempenho do Merge Sort
    clock_t start = clock();
    mergeSort(vetor1, 0, tamanho - 1);
    clock_t end = clock();
    double time_taken_merge = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sequência ordenada (Merge Sort): ");
    printArray(vetor1, tamanho);
    printf("Tempo de execução do Merge Sort: %f segundos\n", time_taken_merge);

    // Teste de desempenho do Bubble Sort
    start = clock();
    bubbleSort(vetor2, tamanho);
    end = clock();
    double time_taken_bubble = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sequência ordenada (Bubble Sort): ");
    printArray(vetor2, tamanho);
    printf("Tempo de execução do Bubble Sort: %f segundos\n", time_taken_bubble);

    return 0;
}
