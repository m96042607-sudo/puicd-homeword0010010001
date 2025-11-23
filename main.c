#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_THRESHOLD 50000   // 小於這個大小就不要開 thread（開太多會變慢）

typedef struct {
    int *arr;
    int left;
    int right;
} Task;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int p = partition(arr, left, right);
        quicksort(arr, left, p - 1);
        quicksort(arr, p + 1, right);
    }
}

void* parallel_quicksort(void* arg) {
    Task* t = (Task*)arg;
    int left = t->left;
    int right = t->right;
    int *arr = t->arr;

    if (right - left < THREAD_THRESHOLD) {
        quicksort(arr, left, right);
        return NULL;
    }

    int p = partition(arr, left, right);

    pthread_t t1, t2;
    Task left_task = {arr, left, p - 1};
    Task right_task = {arr, p + 1, right};

    pthread_create(&t1, NULL, parallel_quicksort, &left_task);
    pthread_create(&t2, NULL, parallel_quicksort, &right_task);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return NULL;
}

int main() {
    int n = 100000;
    int *arr = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000;
    }

    printf("排序開始...\n");

    Task t = {arr, 0, n - 1};
    parallel_quicksort(&t);

    printf("排序完成!\n前 10 個數字: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
