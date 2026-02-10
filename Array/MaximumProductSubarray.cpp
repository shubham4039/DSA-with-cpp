// Problem Link: https://leetcode.com/problems/maximum-product-subarray/
// Problem: Maximum Product Subarray
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Dynamic Programming

/*
APPROACH 1: Brute Force
- Try all subarrays and calculate product
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class SolutionBruteForce {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long ans = nums[0];

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }
        return ans;
    }
};

/*
APPROACH 2: Prefix & Suffix Product (Optimal)
- Handle negative numbers and zeros
- Track product from both ends
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionOptimal {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pref = 1, suff = 1;

        for (int i = 0; i < n; i++) {
            if (pref == 0) pref = 1;
            if (suff == 0) suff = 1;

            pref *= nums[i];
            suff *= nums[n - i - 1];

            ans = max(ans, max(pref, suff));
        }
        return ans;
    }
};
