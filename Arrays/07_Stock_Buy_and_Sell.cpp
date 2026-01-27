/*
===================================================================================
Problem: Stock Buy and Sell – Multiple Transaction Allowed
Difficulty: Medium
Accuracy: 13.43%
Submissions: 194K+
Points: 4

Platform: GeeksforGeeks
===================================================================================

Description:
-------------
The cost of stock on each day is given in an array price[]. Each day you may 
decide to either buy or sell the stock at price[i], you can even buy and sell 
the stock on the same day. Find the maximum profit that you can get.

Note: A stock can only be sold if it has been bought previously and multiple 
stocks cannot be held on any given day.

Examples:
---------
Example 1:
    Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
    Output: 865
    Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210.
                 Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655.
                 Maximum Profit = 210 + 655 = 865.

Example 2:
    Input: prices[] = [4, 2, 2, 2, 4]
    Output: 2
    Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2.
                 Maximum Profit = 2.

Constraints:
------------
- 1 <= prices.size() <= 10^5
- 0 <= prices[i] <= 10^4

Company Tags:
-------------
Paytm, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, Samsung, D-E-Shaw,
Hike, MakeMyTrip, Ola Cabs, Oracle, Walmart, Goldman Sachs, Directi, Intuit,
SAP Labs, Quikr, Facebook, Salesforce, Pubmatic, Sapient, Swiggy

Topic Tags:
-----------
Arrays, Data Structures

===================================================================================
*/

/*
-----------------------------------------------------------------------------------
APPROACH: Greedy (Collect Every Upward Move)
-----------------------------------------------------------------------------------

Key Insight:
Since we can make unlimited transactions, we should capture EVERY price increase.
If prices[i] > prices[i-1], we make a profit by buying on day i-1 and selling on day i.

Why This Works:
- Any profit from holding through multiple days can be broken into daily gains
- Example: Buy at 100, sell at 310 (profit 210) = same as:
  - Buy at 100, sell at 180 (profit 80)
  - Buy at 180, sell at 260 (profit 80)  
  - Buy at 260, sell at 310 (profit 50)
  - Total = 80 + 80 + 50 = 210

Algorithm:
1. Iterate through prices starting from day 1
2. If today's price > yesterday's price, add the difference to profit
3. Return total profit

-----------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        
        // Capture every upward price movement
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;
    }
};

/*
-----------------------------------------------------------------------------------
COMPLEXITY ANALYSIS:
-----------------------------------------------------------------------------------
Time Complexity: O(n)
    - Single pass through the array of n elements

Space Complexity: O(1)
    - Only using a constant amount of extra space (profit variable)

-----------------------------------------------------------------------------------
*/
