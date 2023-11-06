#include <iostream>
#include <cstdlib>

// Function to swap two integers in an array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Standard partition scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized partition scheme
int randomizedPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);

    int pivot = arr[high];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

// Quick sort using standard partition
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Quick sort using randomized partition
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivot);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    int arr[size];
    std::cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    // Sort the array using standard partition quicksort
    quickSort(arr, 0, size - 1);
    std::cout << "Standard Partition QuickSort: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Shuffle the array
    std::random_shuffle(arr, arr + size);

    // Sort the shuffled array using randomized partition quicksort
    randomizedQuickSort(arr, 0, size - 1);
    std::cout << "Randomized Partition QuickSort: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
