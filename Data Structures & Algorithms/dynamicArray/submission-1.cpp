#include <iostream>

class DynamicArray {
public:
    int *arr = nullptr;
    int cap = 1;
    int size = 0;

    DynamicArray(int capacity) {
        arr = (int *) malloc(sizeof(int) * capacity);
        if (arr == nullptr) {
            free(arr);
            exit(-1);
        }
        cap = capacity;
    }

    ~DynamicArray() {
        free(arr);
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
        if (i+1 > size)
            size = i+1;
    }

    void pushback(int n) {
        if (size >= cap)
            resize();

        set(size, n);
    }

    int popback() {
        return arr[--size];
    }

    void resize() {
        int *tmp = (int *) realloc(arr, 2 * cap * sizeof(int));
        if (tmp == nullptr) {
            free(tmp);
            exit(-1);
        }

        arr = tmp;
        cap = cap * 2;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
