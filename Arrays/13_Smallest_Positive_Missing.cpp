/*
 * ============================================================================
 * GFG 160 - Problem 13: Smallest Positive Missing Number
 * ============================================================================
 * Difficulty: Medium
 * Topic: Arrays, Searching, Data Structures, Algorithms
 * 
 * Problem Link: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
 * ============================================================================
 * 
 * Problem Description:
 * You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.
 * 
 * Note: Positive number starts from 1. The array can have negative integers too.
 * 
 * Examples:
 *   Input: arr[] = [2, -3, 4, 1, 1, 7]
 *   Output: 3
 *   Explanation: Smallest positive missing number is 3.
 * 
 *   Input: arr[] = [5, 3, 2, 5, 1]
 *   Output: 4
 *   Explanation: Smallest positive missing number is 4.
 * 
 *   Input: arr[] = [-8, 0, -1, -4, -3]
 *   Output: 1
 *   Explanation: Smallest positive missing number is 1.
 * 
 * Constraints:
 *   - 1 ≤ arr.size() ≤ 10^5
 *   - -10^6 ≤ arr[i] ≤ 10^6
 * 
 * ============================================================================
 * Approach:
 * - Ideally, providing valid numbers exist, `val` should be at index `val - 1` (since 1-based positive integers).
 * - We act like a "Cyclic Sort":
 *   - Iterate through the array.
 *   - While the current element `arr[i]` is a valid positive number (1 <= arr[i] <= n) 
 *     AND it is not in its correct position (arr[i] != arr[arr[i]-1]):
 *     - Swap `arr[i]` with `arr[arr[i]-1]` to place it correctly.
 * - After placing all possible numbers in their correct positions, iterate again.
 * - The first index `i` where `arr[i] != i + 1` means `i + 1` is missing.
 * - If all indices match, then `n + 1` is the missing number.
 * 
 * Time Complexity:  O(n) - Each element is swapped at most once.
 * Space Complexity: O(1) - In-place modification.
 * ============================================================================
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Cyclic Sort: Place each number in its correct position (val -> index val-1)
        for (int i = 0; i < n; i++) {
            // While valid positive number AND not in correct position
            while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        
        // Check for the first missing positive number
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        
        // If all 1..n are present, return n+1
        return n + 1;
    }
};


