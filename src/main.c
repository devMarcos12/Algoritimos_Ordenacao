#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void mergeSort(int *vetor, int tamanho);
void bubbleSort(int *vetor, int tamanho);
void heapSort(int arr[], int n);
void quicksort(int arr[], int inicio, int fim);
void gerarArrayAleatorio(int arr[], int n);

void printArray(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para gerar um array de inteiros aleatórios
void gerarArrayAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000; // Números aleatórios entre 0 e 99.999
    }
}

int main() {
    printf("Iniciando o programa de testes de algoritmos de ordenação.\n");

    FILE *file = fopen("resultados.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int tamanhos[] = {100, 1000, 10000, 50000, 100000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    srand(time(NULL)); // Inicializa a semente para números aleatórios

    for (int t = 0; t < numTamanhos; t++) {
        int n = tamanhos[t];

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        gerarArrayAleatorio(arr, n);

        int *arrBubble = (int *)malloc(n * sizeof(int));
        int *arrMerge = (int *)malloc(n * sizeof(int));
        int *arrSelection = (int *)malloc(n * sizeof(int));
        int *arrInsertion = (int *)malloc(n * sizeof(int));
        int *arrHeap = (int *)malloc(n * sizeof(int));
        int *arrQuick = (int *)malloc(n * sizeof(int));

        // Bubble Sort
        clock_t inicio = clock();
        bubbleSort(arrBubble, n);
        clock_t fim = clock();
        double tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Bubble Sort concluído em %f segundos.\n", tempo_cpu);
        fprintf(file, "Bubble Sort: %f \n", tempo_cpu);

        // Merge Sort
        inicio = clock();
        mergeSort(arrMerge, n);
        fim = clock();
        tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Merge Sort concluído em %f segundos.\n", tempo_cpu);
        fprintf(file, "Merge Sort: %f\n", tempo_cpu);

        // Selection Sort
        inicio = clock();
        selectionSort(arrSelection, n);
        fim = clock();
        tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Selection Sort concluído em %f segundos.\n", tempo_cpu);
        fprintf(file, "Selection Sort: %f\n", tempo_cpu);

        // Insertion Sort
        inicio = clock();
        insertionSort(arrInsertion, n);
        fim = clock();
        tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Insertion Sort concluído em %f segundos.\n", tempo_cpu);
        fprintf(file, "Insertion Sort: %f\n", tempo_cpu);

        // Heap Sort
        inicio = clock();
        heapSort(arrHeap, n);
        fim = clock();
        tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Heap Sort concluído em %f segundos.\n", tempo_cpu);
        fprintf(file, "Heap Sort: %f\n", tempo_cpu);

        // Quick Sort
        inicio = clock();
        quicksort(arrQuick, 0, n - 1);
        fim = clock();
        tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("Quick Sort concluído em %f segundos.\n", tempo_cpu);
        fprintf(file, "Quick Sort: %f\n", tempo_cpu);

        fprintf(file, "\n");

        free(arr);
        free(arrBubble);
        free(arrMerge);
        free(arrSelection);
        free(arrInsertion);
        free(arrHeap);
        free(arrQuick);
    }

    fclose(file);
    printf("Programa concluído. Resultados salvos em 'resultados.txt'.\n");
    return 0;
}

// Funções de ordenação

void merge(int *vetor, int tamanho) {
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    int auxiliar[tamanho];
    while (i < meio && j < tamanho) {
        if (vetor[i] <= vetor[j])
            auxiliar[k] = vetor[i++];
        else
            auxiliar[k] = vetor[j++];
        k++;
    }
    if (i == meio) {
        while (j < tamanho)
            auxiliar[k++] = vetor[j++];
    } else {
        while (i < meio)
            auxiliar[k++] = vetor[i++];
    }
    for (i = 0; i < tamanho; i++)
        vetor[i] = auxiliar[i];
}

void mergeSort(int *vetor, int tamanho) {
    int meio = tamanho / 2;
    if (tamanho > 1) {
        mergeSort(vetor, meio);
        mergeSort(vetor + meio, tamanho - meio);
        merge(vetor, tamanho);
    }
}

void bubbleSort(int *vetor, int tamanho) {
    int atual = 0;
    int proximo = 0;
    int auxiliar = 0;

    for (atual = 1; atual < tamanho; atual++) {
        for (proximo = 0; proximo < tamanho - 1; proximo++) {
            if (vetor[proximo] > vetor[proximo + 1]) {
                auxiliar = vetor[proximo];
                vetor[proximo] = vetor[proximo + 1];
                vetor[proximo + 1] = auxiliar;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i; 
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int particiona(int arr[], int inicio, int fim) {
    int pivo = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[fim]);
    return i + 1;
}

void quicksort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particiona(arr, inicio, fim);
        quicksort(arr, inicio, posicaoPivo - 1);
        quicksort(arr, posicaoPivo + 1, fim);
    }
}
