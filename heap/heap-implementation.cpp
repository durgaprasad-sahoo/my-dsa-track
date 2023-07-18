#include <iostream>
#include <vector>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }

    void deleteFromHeap() {
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i <= size) {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int largestIndex = i;
            if (leftChild <= size && arr[largestIndex] < arr[leftChild]) {
                largestIndex = leftChild;
            }
            if (rightChild <= size && arr[largestIndex] < arr[rightChild]) {
                largestIndex = rightChild;
            }
            if (largestIndex != i) {
                swap(arr[largestIndex], arr[i]);
                i = largestIndex;
            } else {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {
    int largestIndex = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;
    if (leftChild <= n && arr[largestIndex] < arr[leftChild]) {
        largestIndex = leftChild;
    }
    if (rightChild <= n && arr[largestIndex] < arr[rightChild]) {
        largestIndex = rightChild;
    }
    if (largestIndex != i) {
        swap(arr[largestIndex], arr[i]);
        heapify(arr, n, largestIndex);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
    for (int i = n; i >= 2; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}

int main() {
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.deleteFromHeap();
    h.print();

    int arr[12] = {-1, 23, 19, 72, 65, 15, 53, 59, 79, 30, 10, 90};
    int n = 11;
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
