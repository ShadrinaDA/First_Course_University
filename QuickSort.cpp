#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

enum len {
    MAX_LEN = 2000000,
    MIN_LEN = 1
};

void QuickSort(int* ptr, int left_border, int right_border);
void Swap(int* ptr, int index1, int index2);

int main(void) {
    int len_arr;
    if (scanf("%d", &len_arr) != 1 || len_arr > MAX_LEN || len_arr < MIN_LEN) {
        return 0;
    }
    int* ptr = (int*)malloc(len_arr * sizeof(int));
    assert(ptr != NULL);
    for (int i = 0; i < len_arr; ++i) {
        if (scanf("%d", &ptr[i]) != 1) {
            free(ptr);
            return 0;
        }
    }

    QuickSort(ptr, 0, len_arr - 1);
    for (int i = 0; i < len_arr; ++i) {
        printf("%d ", ptr[i]);
    }
    free(ptr);
    return EXIT_SUCCESS;
}

void QuickSort(int* ptr, int left_border, int right_border) {
    int pivot_index = (left_border + right_border) / 2;
    int pivot = ptr[pivot_index], left_index = left_border, right_index = right_border;
    do
    {
        while (ptr[left_index] < pivot) {
            left_index++;
        }
        while (ptr[right_index] > pivot) {
            right_index--;
        }

        if (left_index <= right_index) {
            if (ptr[left_index] > ptr[right_index]) {
                Swap(ptr, left_index, right_index);
            }
            left_index++;
            right_index--;
        }
    } while (left_index <= right_index);

    if (left_index < right_border) {
        QuickSort(ptr, left_index, right_border);
    }
    if (left_border < right_index) {
        QuickSort(ptr, left_border, right_index);
    }
}

void Swap(int* ptr, int index1, int index2) {
    int temp = ptr[index1];
    ptr[index1] = ptr[index2];
    ptr[index2] = temp;
}
