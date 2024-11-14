#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


enum len {
    MAX_LEN = 2000000,
    MIN_LEN = 1
};
void HeapSort(int* arr, int len_arr);
static void Swap(int* arr, int index1, int index2);
void Heap(int* arr, int len_arr);
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

void Heap(int* arr, int num_el) {
    for (int i = (num_el - 1) / 2; i > -1; --i) {
        int child2 = i * 2 + 2;
        if ( child2 <= num_el) {
            if (arr[i] < arr[child2]) {
                Swap(arr, i, child2);
            }
        }
        int child1 = i * 2 + 1;
        if (arr[i] < arr[child1]) {
            Swap(arr, i, child1);
        }
    }
}

void HeapSort(int* arr, int len_arr) {
    int num_elements = len_arr - 1;
    while (num_elements > 0) {
        Heap(arr, num_elements);
        Swap(arr, 0, num_elements);
        --num_elements;
    }
}

void Swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
