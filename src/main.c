#include <stdio.h>
#include <time.h>

void mergeSort(int *vetor, int tamanho);
void bubbleSort(int *vetor, int tamanho);

void printArray(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("resultados.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int arrBubble[] = {64, 34, 25, 12, 22, 11, 90};
    int arrMerge[] = {64, 34, 25, 12, 22, 11, 90};
    int tamanho = sizeof(arrBubble) / sizeof(arrBubble[0]);

    clock_t inicio, fim;
    double tempo_cpu;

    // Teste para Bubble Sort
    inicio = clock();
    bubbleSort(arrBubble, tamanho);
    fim = clock();
    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    fprintf(file, "Bubble Sort: %f\n", tempo_cpu);
    printf("Array ordenado com Bubble Sort: ");
    printArray(arrBubble, tamanho);

    // Teste para Merge Sort
    inicio = clock();
    mergeSort(arrMerge, tamanho);
    fim = clock();
    tempo_cpu = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    fprintf(file, "Merge Sort: %f\n", tempo_cpu);
    printf("Array ordenado com Merge Sort: ");
    printArray(arrMerge, tamanho);

    fclose(file);
    return 0;
}

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
