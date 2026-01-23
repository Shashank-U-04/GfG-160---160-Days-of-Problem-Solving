/*
 * ============================================================================
 * GFG 160 - Problem 03: Reverse an Array
 * ============================================================================
 * Difficulty: Easy
 * Topic: Arrays
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/reverse-an-array/1
 * ============================================================================
 * 
 * Problem Description:
 * You are given an array of integers arr[]. You have to reverse the given array.
 * Note: Modify the array in place.
 * 
 * Examples:
 *   Input:  arr[] = [1, 4, 3, 2, 6, 5]
 *   Output: [5, 6, 2, 3, 4, 1]
 *   Explanation: The first element goes to the last position, the second 
 *                element goes to the second last position and so on.
 * 
 *   Input:  arr[] = [4, 5, 2]
 *   Output: [2, 5, 4]
 *   Explanation: The reversed array will be [2, 5, 4].
 * 
 *   Input:  arr[] = [1]
 *   Output: [1]
 *   Explanation: Single element array remains the same after reversal.
 * 
 * Constraints:
 *   - 1 ≤ arr.size() ≤ 10^5
 *   - 0 ≤ arr[i] ≤ 10^5
 * 
 * Company Tags: Bloomberg, Facebook, TCS, Adobe, Google, Infosys, Capgemini,
 *               Morgan Stanley, Amazon, Microsoft, Apple, Yahoo, PayPal, Uber
 * ============================================================================
 * Approach (Two-Pointer Technique):
 * - Use two pointers: 'i' starting from the beginning and 'j' starting from
 *   the end of the array.
 * - Swap elements at positions i and j, then move i forward and j backward.
 * - Continue until i >= j (pointers meet or cross).
 * - This reverses the array in-place with minimal swaps.
 * 
 * Time Complexity:  O(n) - We traverse half the array performing swaps
 * Space Complexity: O(1) - In-place reversal, no extra space used
 * ============================================================================
 */

#include <vector>
using namespace std;

class Solution {
public:
    void reverseArray(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;
        
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};
