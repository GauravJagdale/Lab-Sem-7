#include <iostream>
#include <algorithm>
using namespace std;

// Define a structure for items, each item has weight and value
struct Item {
    int weight;
    int value;
};

// Comparison function for sorting items based on value per unit weight (greedy strategy)
bool compare(Item a, Item b) {
    return (a.value * 1.0 / a.weight) > (b.value * 1.0 / b.weight);
}

// Function to find the maximum value achievable using fractional knapsack
double fractionalKnapsack(Item items[], int n, int capacity) {
    // Sort the items based on their value-to-weight ratio using the compare function
    sort(items, items + n, compare);
    
    double maxValue = 0.0; // Initialize the maximum value to zero
    
    // Iterate through the sorted items
    for (int i = 0; i < n; i++) {
        // If there is enough capacity for the entire item, add its value
        if (capacity >= items[i].weight) {
            maxValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // If there is not enough capacity for the entire item, add a fraction of its value
            maxValue += (items[i].value * 1.0 / items[i].weight) * capacity;
            break; // No more items can be added
        }
    }
    return maxValue; // Return the maximum value achievable
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    Item items[n]; // Declare an array of items

    // Input weights and values for each item
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    // Call the fractionalKnapsack function to find the maximum value
    double max_value = fractionalKnapsack(items, n, capacity);

    // Output the maximum value achieved
    cout << "Maximum value: " << max_value << endl;

    return 0;
}
