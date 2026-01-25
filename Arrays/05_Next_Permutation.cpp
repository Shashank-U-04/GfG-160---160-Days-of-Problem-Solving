/*
================================================================================
 Problem: Next Permutation
 Platform: GeeksforGeeks (GFG 160 - Day 5)
 Difficulty: Medium
 Accuracy: 40.66%
 Points: 4
 Average Time: 20m
================================================================================

 Description:
 Given an array of integers arr[] representing a permutation, implement the 
 next permutation that rearranges the numbers into the lexicographically next 
 greater permutation. If no such permutation exists, rearrange the numbers 
 into the lowest possible order (i.e., sorted in ascending order).

 Note: A permutation of an array of integers refers to a specific arrangement 
 of its elements in a sequence or linear order.

================================================================================

 Examples:

 Example 1:
   Input:  arr[] = [2, 4, 1, 7, 5, 0]
   Output: [2, 4, 5, 0, 1, 7]
   Explanation: The next permutation of the given array is [2, 4, 5, 0, 1, 7].

 Example 2:
   Input:  arr[] = [3, 2, 1]
   Output: [1, 2, 3]
   Explanation: As arr[] is the last permutation, the next permutation is 
                the lowest one.

 Example 3:
   Input:  arr[] = [3, 4, 2, 5, 1]
   Output: [3, 4, 5, 1, 2]
   Explanation: The next permutation of the given array is [3, 4, 5, 1, 2].

================================================================================

 Constraints:
   - 1 ≤ arr.size() ≤ 10^5
   - 0 ≤ arr[i] ≤ 10^5

 Expected Complexities:
   - Time Complexity: O(n)
   - Auxiliary Space: O(1)

================================================================================

 Company Tags:
   Infosys, Flipkart, Amazon, Microsoft, FactSet, Hike, MakeMyTrip, Google, 
   Qualcomm, Salesforce

 Topic Tags:
   Arrays, Permutation, Constructive Algo, Data Structures

================================================================================

 Approach:
 
 The algorithm follows these steps:
 
 1. Find the Break Point:
    - Traverse from right to left and find the largest index 'i' such that 
      arr[i] < arr[i+1]. This is the "break point" where the decreasing 
      sequence from right ends.
    - If no such index exists (array is in descending order), it's the last 
      permutation.

 2. Find the Next Greater Element:
    - If break point exists (i >= 0), find the smallest element greater than 
      arr[i] from the right side. This will be at index 'j' where arr[j] > arr[i].

 3. Swap:
    - Swap arr[i] with arr[j].

 4. Reverse the Suffix:
    - Reverse the subarray from index i+1 to the end to get the smallest 
      possible suffix (converting descending to ascending order).

 5. Handle Last Permutation:
    - If no break point found (i < 0), reverse the entire array to get the 
      smallest permutation.

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;
        
        // Step 1: Find the break point (rightmost element smaller than its next)
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }
        
        // Step 2 & 3: If break point exists, find next greater and swap
        if (i >= 0) {
            int j = n - 1;
            // Find the rightmost element greater than arr[i]
            while (arr[j] <= arr[i]) {
                j--;
            }
            // Swap arr[i] with arr[j]
            swap(arr[i], arr[j]);
        }
        
        // Step 4: Reverse the suffix starting from i+1
        // (If i < 0, this reverses the entire array for the smallest permutation)
        reverse(arr.begin() + i + 1, arr.end());
    }
};

/*
================================================================================
 Complexity Analysis:
 
 Time Complexity: O(n)
   - Finding break point: O(n) in worst case
   - Finding next greater element: O(n) in worst case  
   - Reversing suffix: O(n) in worst case
   - Total: O(n)

 Space Complexity: O(1)
   - Only using constant extra space for variables i, j, n
   - In-place modification of the array

================================================================================
*/
