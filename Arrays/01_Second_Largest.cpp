/*
 * ============================================================================
 * GFG 160 - Problem 01: Second Largest Element
 * ============================================================================
 * Difficulty: Easy
 * Topic: Arrays
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/second-largest3735/1
 * ============================================================================
 * 
 * Problem Description:
 * Given an array arr[], find the second largest distinct element in the array.
 * If the second largest element does not exist, return -1.
 * 
 * Examples:
 *   Input:  arr[] = [12, 35, 1, 10, 34, 1]
 *   Output: 34
 *   Explanation: 35 is the largest, 34 is second largest.
 * 
 *   Input:  arr[] = [10, 10]
 *   Output: -1
 *   Explanation: All elements are same, no second largest exists.
 * 
 * Constraints:
 *   - 2 ≤ arr.size() ≤ 10^5
 *   - 1 ≤ arr[i] ≤ 10^5
 * 
 * ============================================================================
 * Approach:
 * - Use two variables to track the largest and second largest elements.
 * - Traverse the array once, updating both variables accordingly.
 * - Handle edge case where all elements are identical.
 * 
 * Time Complexity:  O(n) - Single pass through the array
 * Space Complexity: O(1) - Only two extra variables used
 * ============================================================================
 */

#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int getSecondLargest(vector<int>& arr) {
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }

        // If second largest doesn't exist
        if (secondLargest == INT_MIN)
            return -1;

        return secondLargest;
    }
};
