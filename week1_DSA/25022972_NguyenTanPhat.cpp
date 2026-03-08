#include <bits/stdc++.h>
using namespace std;

class SortingAlgorithms {
private:
    // Utility function for merge sort
    static void merge(std::vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1; int n2 = right - mid;
        int l[n1], r[n2];
        for (int i = left; i <= mid; ++i){
            l[i-left] = arr[i];
        }
        for (int j = mid+1; j <= right; ++j){
            r[j-mid-1] = arr[j];
        }
        int i = 0, j = 0, cnt = left;
        while(i < n1 && j < n2){
            if (l[i] < r[j]) arr[cnt++] = l[i++];
            else arr[cnt++] = r[j++];
        }
        while(i < n1){
            arr[cnt++] = l[i++];
        }
        while(j < n2){
            arr[cnt++] = r[j++];
        }
    }

    // Utility function for quick sort
    static int partition(std::vector<int>& arr, int low, int high) {
        // TODO: Implement partition function
        // 1. Select pivot (typically last element)
        // 2. Place pivot at its correct position
        // 3. Place smaller elements to left of pivot and greater to right
        return 0; // Placeholder return
    }

    // Recursive function for merge sort
    static void mergeSortRecursive(std::vector<int>& arr, int left, int right) {
        if (left < right){
            int mid = (left+right)/2;
            mergeSortRecursive(arr, left, mid);
            mergeSortRecursive(arr,mid+1, right);
            merge(arr, left, mid, right);
        }
    }

    // Recursive function for quick sort
    static void quickSortRecursive(std::vector<int>& arr, int low, int high) {
        // TODO: Implement recursive quick sort
        // 1. Check if low < high
        // 2. Get partition index
        // 3. Sort elements before and after partition
    }

public:
    // Bubble Sort
    static void bubbleSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; ++i){
            int tmp = 1;
            for (int j = i+1; j < n; ++j){
                if (arr[i] > arr[j]){
                    // int a;
                    // a = arr[i];
                    // arr[i] = arr[j];
                    // arr[j] = a;
                    swap(arr[i], arr[j]);
                    tmp = 0;
                }
            }
            if(tmp){
                return;
            }
        }
    }

    // Selection Sort
    static void selectionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; ++i){
            int min = 1e9+7;
            int min_idx = n-1;
            for (int j = i+1; j < n; ++j){
                if (arr[j] < min){
                    min = arr[j];
                    min_idx = j;
                }
            }
            if (arr[min_idx] < arr[i]){
                swap(arr[min_idx], arr[i]);
            }
        }
    }
    // Insertion Sort
    static void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i){
            int idx = i-1; int x = arr[i];
            while (idx >= 0 && x < arr[idx]){
                arr[idx+1] = arr[idx];
                --idx;
            }
            arr[idx+1] = x;
        }
    }

    // Merge Sort (public interface)
    static void mergeSort(std::vector<int>& arr) {
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

    // Quick Sort (public interface)
    static void quickSort(std::vector<int>& arr) {
        quickSortRecursive(arr, 0, arr.size() - 1);
    }
};

// Utility function to print array
void printArray(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Testing function - DO NOT MODIFY
void testSortingAlgorithms() {
    std::vector<std::vector<int>> testArrays = {
        {64, 34, 25, 12, 22, 11, 90},
        {38, 27, 43, 3, 9, 82, 10},
        {8, 4, 23, 42, 16, 15},
        {122, 45, 75, 90, 32, 11},
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
    };

    std::cout << "Testing Bubble Sort:\n";
    std::vector<int> arr1 = testArrays[0];
    std::cout << "Original array: ";
    printArray(arr1);
    SortingAlgorithms::bubbleSort(arr1);
    std::cout << "Sorted array: ";
    printArray(arr1);
    std::cout << std::endl;

    std::cout << "Testing Selection Sort:\n";
    std::vector<int> arr2 = testArrays[1];
    std::cout << "Original array: ";
    printArray(arr2);
    SortingAlgorithms::selectionSort(arr2);
    std::cout << "Sorted array: ";
    printArray(arr2);
    std::cout << std::endl;

    std::cout << "Testing Insertion Sort:\n";
    std::vector<int> arr3 = testArrays[2];
    std::cout << "Original array: ";
    printArray(arr3);
    SortingAlgorithms::insertionSort(arr3);
    std::cout << "Sorted array: ";
    printArray(arr3);
    std::cout << std::endl;

    std::cout << "Testing Merge Sort:\n";
    std::vector<int> arr4 = testArrays[3];
    std::cout << "Original array: ";
    printArray(arr4);
    SortingAlgorithms::mergeSort(arr4);
    std::cout << "Sorted array: ";
    printArray(arr4);
    std::cout << std::endl;

    std::cout << "Testing Quick Sort:\n";
    std::vector<int> arr5 = testArrays[4];
    std::cout << "Original array: ";
    printArray(arr5);
    SortingAlgorithms::quickSort(arr5);
    std::cout << "Sorted array: ";
    printArray(arr5);
}

int main() {
    testSortingAlgorithms();
    return 0;
}
