// Problem Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Problem: Subarray Sum Equals K
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Prefix Sum / Hashing
// Approach: Use prefix sum and unordered_map

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int prefixSum = 0, count = 0;

        freq[0] = 1;
        for (int x : nums) {
            prefixSum += x;
            int needed = prefixSum - k;
            if (freq.find(needed) != freq.end()) {
                count += freq[needed];
            }
            freq[prefixSum]++;
        }
        return count;
    }
};
