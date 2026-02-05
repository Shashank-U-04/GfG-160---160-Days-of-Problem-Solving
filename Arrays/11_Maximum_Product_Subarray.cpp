#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Maximum Product Subarray
 * Difficulty: Medium
 * Accuracy: 18.09%
 * Submissions: 493K+
 * Points: 4
 * 
 * Given an array arr[] that contains positive and negative integers (may contain 0 as well). 
 * Find the maximum product that we can get in a subarray of arr[].
 * 
 * Note: It is guaranteed that the answer fits in a 32-bit integer.
 * 
 * Examples:
 * 
 * Input: arr[] = [-2, 6, -3, -10, 0, 2]
 * Output: 180
 * Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.
 * 
 * Input: arr[] = [-1, -3, -10, 0, 6]
 * Output: 30
 * Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.
 * 
 * Input: arr[] = [2, 3, 4] 
 * Output: 24 
 * Explanation: For an array with all positive elements, the result is product of all elements.
 * 
 * Constraints:
 * 1 <= arr.size() <= 10^6
 * -10 <= arr[i] <= 10
 */

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        if (arr.empty()) return 0;

        int maxp = arr[0], minp = arr[0], ans = arr[0];
    
        for(size_t i = 1; i < arr.size(); i++){
            // If current element is negative, swap max and min
            if(arr[i] < 0) swap(maxp, minp);
            
            maxp = max(arr[i], maxp * arr[i]);
            minp = min(arr[i], minp * arr[i]);
            ans = max(ans, maxp);
        }
        return ans;    
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {-2, 6, -3, -10, 0, 2};
    cout << "Test Case 1: " << sol.maxProduct(arr1) << " (Expected: 180)" << endl;

    // Test Case 2
    vector<int> arr2 = {-1, -3, -10, 0, 6};
    cout << "Test Case 2: " << sol.maxProduct(arr2) << " (Expected: 30)" << endl;

    // Test Case 3
    vector<int> arr3 = {2, 3, 4};
    cout << "Test Case 3: " << sol.maxProduct(arr3) << " (Expected: 24)" << endl;

    return 0;
}
