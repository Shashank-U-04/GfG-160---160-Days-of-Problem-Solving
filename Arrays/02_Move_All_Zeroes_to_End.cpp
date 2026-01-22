/*
 * ============================================================================
 * GFG 160 - Problem 02: Move All Zeroes to End
 * ============================================================================
 * Difficulty: Easy
 * Topic: Arrays
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1
 * ============================================================================
 * 
 * Problem Description:
 * Given an array arr[] of non-negative integers, move all the zeros to the 
 * right end while maintaining the relative order of non-zero elements.
 * The operation must be performed in-place (no extra array allowed).
 * 
 * Examples:
 *   Input:  arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
 *   Output: [1, 2, 4, 3, 5, 0, 0, 0]
 *   Explanation: Three 0s are moved to the end.
 * 
 *   Input:  arr[] = [10, 20, 30]
 *   Output: [10, 20, 30]
 *   Explanation: No zeros present, array remains unchanged.
 * 
 *   Input:  arr[] = [0, 0]
 *   Output: [0, 0]
 *   Explanation: All zeros, no change needed.
 * 
 * Constraints:
 *   - 1 ≤ arr.size() ≤ 10^5
 *   - 0 ≤ arr[i] ≤ 10^5
 * 
 * Company Tags: Paytm, Amazon, Microsoft, Samsung, SAP Labs, LinkedIn, Bloomberg
 * ============================================================================
 * Approach (Two-Pointer Technique):
 * - Use a pointer 'j' to track the position where the next non-zero element
 *   should be placed.
 * - Traverse the array with pointer 'i'. When a non-zero element is found,
 *   swap it with the element at position 'j' and increment 'j'.
 * - This ensures all non-zero elements are moved to the front in order,
 *   and zeros naturally shift to the end.
 * 
 * Time Complexity:  O(n) - Single pass through the array
 * Space Complexity: O(1) - In-place swapping, no extra space used
 * ============================================================================
 */

#include <vector>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0;  // Pointer for the next non-zero position
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};
