#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack_dp(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = values.size(); // Number of items

    // Create a 2D DP table with dimensions (n+1) x (capacity+1), initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table iteratively
    for (int i = 1; i <= n; ++i) { // Iterate through items
        for (int w = 1; w <= capacity; ++w) { // Iterate through capacities
            if (weights[i - 1] <= w) { // Check if the current item's weight fits in the current capacity
                // Take the maximum value of including or excluding the current item
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]], // Include the current item
                    dp[i - 1][w]                                   // Exclude the current item
                );
            } else {
                // If the item's weight exceeds the current capacity, exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell contains the maximum value for the given capacity
    return dp[n][capacity];
}

int main() {
    // Weights of items
    vector<int> weights = {1, 2, 3, 5};

    // Values of items
    vector<int> values = {1, 6, 10, 16};

    // Maximum weight capacity of the knapsack
    int capacity = 7;

    // Call the DP function and print the result
    cout << "Maximum value using Dynamic Programming: " 
         << knapsack_dp(weights, values, capacity) << endl;

    return 0;
}
