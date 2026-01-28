/*
===================================================================================
Problem: Stock Buy and Sell – Max one Transaction Allowed
Difficulty: Easy
Accuracy: 49.33%
Submissions: 126K+
Points: 2

Platform: GeeksforGeeks
===================================================================================

Description:
-------------
Given an array prices[] of length n, representing the prices of the stocks on 
different days. The task is to find the maximum profit possible by buying and 
selling the stocks on different days when at most one transaction is allowed. 
Here one transaction means 1 buy + 1 Sell. If it is not possible to make a 
profit then return 0.

Note: Stock must be bought before being sold.

Examples:
---------
Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 
             at price = 9. Hence, the profit is 8.

Input: prices[] = [7, 6, 4, 3, 1]
Output: 0 
Explanation: Here the prices are in decreasing order, hence if we buy any day 
             then we cannot sell it at a greater price. Hence, the answer is 0.

Input: prices[] = [1, 3, 6, 9, 11]
Output: 10 
Explanation: Since the array is sorted in increasing order, we can make maximum 
             profit by buying at price[0] and selling at price[n-1].

Constraints:
------------
1 <= prices.size() <= 10^5
0 <= prices[i] <= 10^4

Expected Complexities:
----------------------
Time Complexity: O(n)
Auxiliary Space: O(1)

Company Tags:
-------------
Bloomberg, Facebook, Intel, Infosys, Zoho, Morgan Stanley, Amazon, Microsoft, 
Samsung, Yahoo, PayPal, Nvidia, Oracle, Visa, Walmart, Goldman Sachs, TCS, 
Adobe, Google, IBM, Accenture, Apple, Uber

Topic Tags:
-----------
Greedy, Arrays

===================================================================================
*/

/*
-----------------------------------------------------------------------------------
APPROACH: Single Pass (Min Price So Far)
-----------------------------------------------------------------------------------

Key Insight:
To maximize profit with only ONE transaction, we need to find the largest difference 
between a selling price (current day) and the minimum buying price seen so far.

Algorithm:
1. Initialize `minP` (minimum price) to the first element.
2. Initialize `maxP` (maximum profit) to 0.
3. Iterate through the array starting from the second element:
   - Update `minP` = min(minP, prices[i]).
   - Update `maxP` = max(maxP, prices[i] - minP).
4. Return `maxP`.

Time Complexity: O(N) - Single pass.
Space Complexity: O(1) - Only two variables used.

-----------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        
        int minP = prices[0];
        int maxP = 0;
        
        for(int i = 1; i < prices.size(); i++){
            // If we find a lower buying price, update minP
            if(prices[i] < minP) {
                minP = prices[i];
            }
            // Else, check if selling today gives a better profit
            else {
                maxP = max(maxP, prices[i] - minP);
            }
        }
        return maxP;
    }
};
