/*
===================================================================================
Problem: Minimize the Heights II
Difficulty: Medium
Accuracy: 15.06%
Submissions: 771K+
Points: 4

Platform: GeeksforGeeks
===================================================================================

Description:
-------------
Given an array arr[] denoting heights of n towers and a positive integer k.

For each tower, you must perform exactly one of the following operations exactly once.
- Increase the height of the tower by k
- Decrease the height of the tower by k

Find out the minimum possible difference between the height of the shortest and 
tallest towers after you have modified each tower.

Note: It is compulsory to increase or decrease the height by k for each tower. 
After the operation, the resultant array should not contain any negative integers.

Examples:
---------
Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [1+k, 5-k, 8-k, 10-k] = [3, 3, 6, 8]. 
             The difference between the largest and the smallest is 8-3 = 5.

Input: k = 3, arr[] = [3, 9, 12, 16, 20]
Output: 11
Explanation: The array can be modified as [3+k, 9+k, 12-k, 16-k, 20-k] = [6, 12, 9, 13, 17]. 
             The difference between the largest and the smallest is 17-6 = 11. 

Constraints:
------------
1 <= k <= 10^7
1 <= n <= 10^5
1 <= arr[i] <= 10^7

Expected Complexities:
----------------------
Time Complexity: O(n log n)
Auxiliary Space: O(1)

Company Tags:
-------------
Microsoft, Adobe

Topic Tags:
-----------
Arrays, Greedy

===================================================================================
*/

/*
-----------------------------------------------------------------------------------
APPROACH: Sorting and Greedy Split
-----------------------------------------------------------------------------------

Key Insight:
To minimize the difference between the maximum and minimum heights, we first sort 
the array. This groups closer heights together.

After sorting, the initial answer is `arr[n-1] - arr[0]` (if we either increase all 
or decrease all, the difference remains same as original).

Ideally, for a sorted array, to minimize the range, we should increase the smaller 
elements (left side) and decrease the larger elements (right side). There is some 
split point `i` such that elements `0` to `i-1` are increased by `k`, and elements 
`i` to `n-1` are decreased by `k`.

Algorithm:
1. Sort the array `arr`.
2. Initial `ans` = `arr[n-1] - arr[0]`.
3. Iterate `i` from `1` to `n-1` (considering `i` as the start of the decreased segment).
   - If `arr[i] - k < 0`, we skip this split because heights cannot be negative.
   - Possible new minimum height is `min(arr[0] + k, arr[i] - k)`.
     (The smallest could come from the first element raised, or the current element lowered).
   - Possible new maximum height is `max(arr[i-1] + k, arr[n-1] - k)`.
     (The largest could come from the previous element raised, or the last element lowered).
   - Update `ans` = `min(ans, max_height - min_height)`.
4. Return `ans`.

Time Complexity: O(N log N) - Due to sorting.
Space Complexity: O(1) - No extra space used besides variables.

-----------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;
        
        sort(arr.begin(), arr.end());
        
        int ans = arr[n-1] - arr[0];
        
        // We iterate and try to make a cut between i-1 and i
        // arr[0...i-1] get +k
        // arr[i...n-1] get -k
        for(int i = 1; i < n; i++){
            if(arr[i] - k < 0) continue; // Height cannot be negative
            
            int minn = min(arr[0] + k, arr[i] - k);
            int maxx = max(arr[i-1] + k, arr[n-1] - k);
            
            ans = min(ans, maxx - minn);
        }
        return ans;
    }
};
