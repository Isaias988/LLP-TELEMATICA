//Utilizando Quicksort e MergeSort:
//Isaias Fabricio da Costa - LLP 2023.2
//QuickSort:
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolha o último elemento como pivô
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


//No caso do QuickSort, a estratégia usada para escolher o pivô no código de exemplo é simplesmente
//escolher o último elemento como pivô. Isso não é a estratégia mais eficiente, pois em casos específicos,
//pode resultar em um desempenho pior. Estratégias mais avançadas, como escolher o pivô de forma a minimizar
//a complexidade de tempo média, são preferíveis.



//MergeSort
#include <stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


//Quanto ao número de testes executados no exemplo, o QuickSort é aplicado a um array de 6 elementos
//e, portanto, o código de ordenação foi testado com esse array. O MergeSort é aplicado a um array
//de 6 elementos na atividade. Portanto, 6 elementos foram ordenados na atividade.