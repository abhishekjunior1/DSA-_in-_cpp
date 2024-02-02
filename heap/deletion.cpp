#include <iostream>

using namespace std;

// Function to heapify a subtree with the root at the given index
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min-heap from the given array
void buildMinHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to delete the specified element from the min-heap
void deleteElement(int arr[], int& n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            break;
    }

    if (i == n) {
        cout<<"nhi mila"<<endl;
        // Key not found in the heap
        return;
    }

    swap(arr[i], arr[n - 1]);
    n--;
    buildMinHeap(arr, n);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildMinHeap(arr, n);

    int key;
    cin >> key;

    deleteElement(arr, n, key);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
