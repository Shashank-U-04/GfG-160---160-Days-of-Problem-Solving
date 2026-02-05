/*
 * ============================================================================
 * GFG 160 - Problem 12: Max Circular Subarray Sum
 * ============================================================================
 * Difficulty: Hard
 * Topic: Arrays, Data Structures, Kadane, Algorithms
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1
 * ============================================================================
 * 
 * Problem Description:
 * You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. 
 * In a circular array, the subarray can start at the end and wrap around to the beginning. 
 * Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.
 * 
 * Note: It is guaranteed that the answer fits in a 32-bit integer.
 * 
 * Examples:
 *   Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
 *   Output: 22
 *   Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, 
 *   we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
 * 
 *   Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
 *   Output: 23
 *   Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
 * 
 *   Input: arr[] = [5, -2, 3, 4]
 *   Output: 12
 *   Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.
 * 
 * Constraints:
 *   - 1 ≤ arr.size() ≤ 10^5
 *   - -10^4 ≤ arr[i] ≤ 10^4
 * 
 * ============================================================================
 * Approach:
 * - The maximum circular subarray sum can be either:
 *   1. The maximum subarray sum in the normal (linear) array (using Kadane's Algorithm).
 *   2. The total sum of the array minus the minimum subarray sum (which corresponds to the maximum sum wrapping around).
 * - We compute four values in a single pass:
 *   - `maxsum`: Maximum subarray sum (standard Kadane's).
 *   - `minsum`: Minimum subarray sum (standard Kadane's logic but for minimum).
 *   - `total`: Sum of all elements.
 * - Corner Case: If all elements are negative, `maxsum` will be the maximum single element (negative), 
 *   and `total - minsum` sum might be 0 (empty subarray, but problem asks for non-empty).
 *   In this case, the answer should be `maxsum`.
 * - Result is `max(maxsum, total - minsum)` unless `maxsum < 0`, in which case it is `maxsum`.
 * 
 * Time Complexity:  O(n) - Single pass through the array.
 * Space Complexity: O(1) - Constant extra space used.
 * ============================================================================
 */

#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int total = 0;
        int currmax = 0, maxsum = INT_MIN;
        int currmin = 0, minsum = INT_MAX;
        
        for(int i: arr){
            total += i;
            
            // Kadane's for Max Subarray Sum
            currmax = max(i, currmax + i);
            maxsum = max(maxsum, currmax);
            
            // Kadane's for Min Subarray Sum
            currmin = min(i, currmin + i);
            minsum = min(minsum, currmin);
        }
        
        // If all numbers are negative, maxsum is the answer
        if(maxsum < 0) return maxsum;
        
        // Otherwise, max of linear max or circular max (total - minsum)
        return max(maxsum, total - minsum);
    }
};


