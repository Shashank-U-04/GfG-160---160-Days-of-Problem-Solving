/*
 * ============================================================================
 * GFG 160 - Problem 04: Rotate Array
 * ============================================================================
 * Difficulty: Medium
 * Topic: Arrays
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1
 * ============================================================================
 * 
 * Problem Description:
 * Given an array arr[]. Rotate the array to the left (counter-clockwise 
 * direction) by d steps, where d is a positive integer. Do the mentioned 
 * change in the array in place.
 * Note: Consider the array as circular.
 * 
 * Examples:
 *   Input:  arr[] = [1, 2, 3, 4, 5], d = 2
 *   Output: [3, 4, 5, 1, 2]
 *   Explanation: When rotated by 2 elements, it becomes 3 4 5 1 2.
 * 
 *   Input:  arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
 *   Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
 *   Explanation: When rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
 * 
 *   Input:  arr[] = [7, 3, 9, 1], d = 9
 *   Output: [3, 9, 1, 7]
 *   Explanation: When we rotate 9 times, we'll get 3 9 1 7 as resultant array.
 * 
 * Constraints:
 *   - 1 ≤ arr.size(), d ≤ 10^5
 *   - 0 ≤ arr[i] ≤ 10^5
 * 
 * Company Tags: Amazon, Microsoft, MAQ Software
 * ============================================================================
 * Approach (Reversal Algorithm):
 * - First, handle the case where d > n by taking d = d % n (since rotating
 *   by n elements brings the array back to its original state).
 * - Reverse the first d elements.
 * - Reverse the remaining (n - d) elements.
 * - Reverse the entire array.
 * - This effectively rotates the array left by d positions in-place.
 * 
 * Time Complexity:  O(n) - Each element is visited at most twice
 * Space Complexity: O(1) - In-place rotation, no extra space used
 * ============================================================================
 */

#include <vector>
using namespace std;

class Solution {
public:
    void reverse(vector<int>& arr, int l, int r) {
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // Handle cases where d > n
        
        reverse(arr, 0, d - 1);      // Reverse first d elements
        reverse(arr, d, n - 1);      // Reverse remaining elements
        reverse(arr, 0, n - 1);      // Reverse entire array
    }
};
