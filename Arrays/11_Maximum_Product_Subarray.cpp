/*
 * ============================================================================
 * GFG 160 - Problem 11: Maximum Product Subarray
 * ============================================================================
 * Difficulty: Medium
 * Topic: Arrays, Dynamic Programming, Data Structures, Algorithms
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
 * ============================================================================
 * 
 * Problem Description:
 * Given an array arr[] that contains positive and negative integers (may contain 0 as well). 
 * Find the maximum product that we can get in a subarray of arr[].
 * 
 * Note: It is guaranteed that the answer fits in a 32-bit integer.
 * 
 * Examples:
 *   Input: arr[] = [-2, 6, -3, -10, 0, 2]
 *   Output: 180
 *   Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.
 * 
 *   Input: arr[] = [-1, -3, -10, 0, 6]
 *   Output: 30
 *   Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.
 * 
 *   Input: arr[] = [2, 3, 4] 
 *   Output: 24 
 *   Explanation: For an array with all positive elements, the result is product of all elements.
 * 
 * Constraints:
 *   - 1 ≤ arr.size() ≤ 10^6
 *   - -10 ≤ arr[i] ≤ 10
 * 
 * ============================================================================
 * Approach:
 * - We need to track both the maximum and minimum product ending at the current position because 
 *   multiplying a negative number by a negative minimum product can yield a large positive maximum product.
 * - Initialize `maxp`, `minp`, and `ans` to the first element of the array.
 * - Iterate from the second element to the end:
 *     - If the current element is negative, swap `maxp` and `minp`. 
 *       (Because multiplying by a negative flips the largest to smallest and vice versa).
 *     - Update `maxp` to include the current element: `max(arr[i], maxp * arr[i])`.
 *     - Update `minp` to include the current element: `min(arr[i], minp * arr[i])`.
 *     - Update `ans` with the maximum value found so far.
 * 
 * Time Complexity:  O(n) - Single pass through the array.
 * Space Complexity: O(1) - Constant extra space used.
 * ============================================================================
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        if (arr.empty()) return 0; // Handle empty case if necessary, though constraints say size >= 1

        int maxp = arr[0], minp = arr[0], ans = arr[0];
    
        for(size_t i = 1; i < arr.size(); i++){
            // If current element is negative, swap max and min
            if(arr[i] < 0) swap(maxp, minp);
            
            // Calculate max and min ending at current index
            maxp = max(arr[i], maxp * arr[i]);
            minp = min(arr[i], minp * arr[i]);
            
            // Update global answer
            ans = max(ans, maxp);
        }
        return ans;    
    }
};
