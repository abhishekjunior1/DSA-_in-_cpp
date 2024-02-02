#include <iostream>

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid-start+1; // Size of the left subarray
    int n2 =end-mid+1;       // Size of the right subarray

    int left[n1], right[n2]; // Create temporary arrays for the left and right subarrays

    // Copy data to the temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Merge the two subarrays back into the original array
    int i = 0; // Initial index of the left subarray
    int j = 0; // Initial index of the right subarray
    int k = start; // Initial index of the merged subarray

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2; // Calculate the middle index

        // Recursive calls to divide the array into subarrays
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the subarrays
        merge(arr, start, mid, end);
    }
    return;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7,122};//6
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
