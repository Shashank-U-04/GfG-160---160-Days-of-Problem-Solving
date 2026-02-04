/*
 * ============================================================================
 * GFG 160 - Problem 10: Kadane's Algorithm
 * ============================================================================
 * Difficulty: Medium
 * Topic: Arrays, Dynamic Programming
 * 
 * Problem Link: https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
 * ============================================================================
 * 
 * Problem Description:
 * You are given an integer array arr[]. You need to find the maximum sum of a 
 * subarray (containing at least one element) in the array arr[].
 * 
 * Note: A subarray is a continuous part of an array.
 * 
 * Examples:
 *   Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
 *   Output: 11
 *   Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
 * 
 *   Input: arr[] = [-2, -4]
 *   Output: -2
 *   Explanation: The subarray [-2] has the largest sum -2.
 * 
 *   Input: arr[] = [5, 4, 1, 7, 8]
 *   Output: 25
 *   Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
 * 
 * Constraints:
 *   - 1 ≤ arr.size() ≤ 10^5
 *   - -10^4 ≤ arr[i] ≤ 10^4
 * 
 * ============================================================================
 * Approach:
 * - Initialize `maxsum` to the smallest possible integer and `currsum` to 0.
 * - Iterate through the array:
 *     - Add the current element to `currsum`.
 *     - If `currsum` becomes smaller than the current element (meaning previous subarray sum was negative), 
 *       restart the subarray from the current element. This is equivalent to `currsum = max(arr[i], currsum + arr[i])`.
 *     - Update `maxsum` with the maximum of `maxsum` and `currsum`.
 * - Return `maxsum` after the loop.
 * 
 * Time Complexity:  O(n) - Single pass through the array.
 * Space Complexity: O(1) - Constant extra space used.
 * ============================================================================
 */

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxsum = INT_MIN, currsum = 0;
        for(int i=0; i<arr.size(); i++){
            currsum = max(arr[i], currsum+arr[i]);
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};
