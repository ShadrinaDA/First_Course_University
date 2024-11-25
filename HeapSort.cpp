#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
enum len {
    MAX_LEN = 2000000,
    MIN_LEN = 1
};

void HeapSort(int* arr, int len_arr);
static void Swap(int* el1, int* el2);
void Heapify(int* arr, int len_arr);

int main_1(void) {
    int len_arr;
    if (scanf("%d", &len_arr) != 1 || len_arr > MAX_LEN || len_arr < MIN_LEN) {
        return 0;
    }
    int* arr = (int*)malloc(len_arr * sizeof(int));
    assert(arr != NULL);
    for (int i = 0; i < len_arr; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 0;
        }
    }

    HeapSort(arr, len_arr);
    for (int i = 0; i < len_arr; ++i) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return EXIT_SUCCESS;
}

void Heapify(int* arr, int num_el) {
    int child2 = num_el * 2 + 2, max = arr[num_el];
        if ( child2 <= num_el && arr[num_el] < arr[child2]) {
            max = arr[child2];
        }
        int child1 = num_el * 2 + 1;
        if (child1 <= num_el && arr[num_el] < arr[child1]) {
            max = arr[child1];
        }
        if (max > arr[num_el]) {
            Swap(&arr[num_el], &max);
        }
}

void HeapSort(int* arr, int len_arr) {
    for (int i = (len_arr - 1) / 2; i > 0; --i) {
        Heapify(arr, i);
    }
    for (int i = len_arr - 1; i > 0; --i) {
        Heapify(arr, i);
        Swap(&arr[0], &arr[i]);
    }
}

void Swap(int* el1, int* el2) {
    int temp = *el1;
    *el1 = *el2;
    *el2 = temp;
}
