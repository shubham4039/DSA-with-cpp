// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Problem: Best Time to Buy and Sell Stock
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Greedy
// Approach: Track minimum price and maximum profit

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};
