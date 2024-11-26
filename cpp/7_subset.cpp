#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to find all subsets that sum up to the target
void helper(const vector<int> &nums, int target, int index, int current_sum, vector<int> &current_subset) {
    // Base case: If the current subset's sum equals the target, print the subset
    if (current_sum == target) {
        for (int num : current_subset) {
            cout << num << " "; // Print each number in the subset
        }
        cout << endl;
        return;
    }

    int prev_element = -1; // To avoid duplicate subsets

    // Iterate through the array starting from the current index
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates by checking if the current number equals the previous one
        if (nums[i] != prev_element) {
            // Stop exploring further if adding the current number exceeds the target
            if (nums[i] + current_sum > target) {
                break;
            }

            // Include the current number in the subset
            current_subset.push_back(nums[i]);

            // Update the previous element to avoid duplicates
            prev_element = nums[i];

            // Recursively call the helper to explore further elements
            helper(nums, target, i + 1, current_sum + nums[i], current_subset);

            // Backtrack by removing the last added number from the subset
            current_subset.pop_back();
        }
    }
}

// Main function to find subsets with the given target sum
void findSubset(vector<int> &nums, int target) {
    // Sort the array to handle duplicates and enable early termination
    sort(nums.begin(), nums.end());

    vector<int> current_subset; // To store the current subset

    // Call the helper function with the initial parameters
    helper(nums, target, 0, 0, current_subset);
}

int main() {
    vector<int> nums = {1, 2, 5, 6, 8}; // Input array of numbers
    int target = 9;                     // Target sum

    // Call the function to find subsets
    findSubset(nums, target);

    return 0;
}
