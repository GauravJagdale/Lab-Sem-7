#include <iostream>
using namespace std;

// Utility function to return the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 knapsack problem
int knapSack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];

    // Initialize the dynamic programming table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;  // Base case: No items or no capacity
            else if (wt[i - 1] <= w) {
                // If the weight of the current item is less than or equal to the available capacity
                // Choose the maximum of including the current item or excluding it
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                // If the weight of the current item is more than the available capacity
                // Exclude the current item
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];  // Return the maximum profit achievable
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int profit[n];
    int weight[n];

    cout << "Enter the profits of items: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    int W;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    // Call the knapSack function to find the maximum profit
    int maxProfit = knapSack(W, weight, profit, n);

    // Output the maximum profit achieved
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
