// Problem Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// Problem: Subtract the Product and Sum of Digits of an Integer
// Platform: LeetCode
// Difficulty: Easy
// Approach: Traverse digits, calculate product and sum
// Time Complexity: O(log10(n))
// Space Complexity: O(1)

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, prod = 1;
        while (n) {
            int digit = n % 10;
            sum += digit;
            prod *= digit;
            n /= 10;
        }
        return prod - sum;
    }
};
