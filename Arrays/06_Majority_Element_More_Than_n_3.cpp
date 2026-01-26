/*
================================================================================
📌 Problem: Majority Element - More Than n/3
================================================================================

🔹 Difficulty: Medium
🔹 Accuracy: 48.1%
🔹 Points: 4
🔹 Average Time: 15m

📝 Description:
Given an array arr[] consisting of n integers, the task is to find all the 
array elements which occur more than floor(n/3) times.

Note: The returned array of majority elements should be sorted.

📊 Examples:

Example 1:
  Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
  Output: [1, 2]
  Explanation: The frequency of 1 and 2 is 3, which is more than 
               floor(n/3) = 8/3 = 2.

Example 2:
  Input: arr[] = [-5, 3, -5]
  Output: [-5]
  Explanation: The frequency of -5 is 2, which is more than 
               floor(n/3) = 3/3 = 1.

Example 3:
  Input: arr[] = [3, 2, 2, 4, 1, 4]
  Output: []
  Explanation: There is no majority element.

📏 Constraints:
  • 1 ≤ arr.size() ≤ 10^6
  • -10^5 ≤ arr[i] ≤ 10^5

⏱️ Expected Complexities:
  • Time Complexity: O(n)
  • Auxiliary Space: O(1)

🏢 Company Tags: Bloomberg, Salesforce, Accenture, Microsoft, TCS, Google
📚 Topic Tags: Arrays, Data Structures, Algorithms, Hash

================================================================================
💡 Approach 1: Using HashMap (O(n) space)
================================================================================

This approach uses an unordered_map to count the frequency of each element,
then filters elements with frequency > n/3.

Steps:
1. Create a frequency map for all elements
2. Iterate through the map and collect elements with count > n/3
3. Sort the result if needed (at most 2 elements possible)

Time Complexity: O(n) - Single pass to count + O(1) for sorting (at most 2 elements)
Space Complexity: O(n) - For the hash map

================================================================================
💡 Approach 2: Sorting Based (O(n log n) time)
================================================================================

This approach sorts the array first, then counts consecutive elements.

Steps:
1. Sort the array
2. Count consecutive occurrences of each element
3. If count > n/3, add to result

Time Complexity: O(n log n) - Due to sorting
Space Complexity: O(1) - Apart from the result array

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Approach 1: Using HashMap
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> res;
        
        // Count frequency of each element
        for(int i: arr) freq[i]++;
        
        // Find elements with frequency > n/3
        for(auto i: freq){
            int ele = i.first;
            int cnt = i.second;
            
            if(cnt > n/3) res.push_back(ele);
        }
        
        // Sort the result (at most 2 elements, so O(1))
        if(res.size() == 2 && res[0] > res[1]) swap(res[0], res[1]);
        
        return res;
    }
    
    // Approach 2: Sorting Based
    vector<int> findMajoritySorting(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int n = arr.size();
        
        // Count consecutive occurrences
        for(int i = 0; i < n;){
            int j = i;
            while(j < n && arr[j] == arr[i]) j++;
            
            // If count > n/3, add to result
            if(j - i > n/3) ans.push_back(arr[i]);
            i = j;
        }
        
        return ans;
    }
};

/*
================================================================================
📊 Complexity Analysis:

Approach 1 (HashMap):
  • Time Complexity: O(n)
    - Single pass to count frequencies: O(n)
    - At most n entries in map, but we only add at most 2 to result
    - Sorting result is O(1) since at most 2 elements

  • Space Complexity: O(n)
    - Hash map stores at most n unique elements

Approach 2 (Sorting):
  • Time Complexity: O(n log n)
    - Sorting takes O(n log n)
    - Single pass to count: O(n)

  • Space Complexity: O(1)
    - No extra space apart from result array

Key Insight:
  - At most 2 elements can have frequency > n/3
  - If an element appears more than n/3 times, there can be at most 2 such elements
    because 3 * (n/3) = n, so we can't fit 3 elements each appearing > n/3 times

================================================================================
*/
