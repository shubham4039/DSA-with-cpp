// Problem Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Problem: Sort Integers by The Number of 1 Bits
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Bit Manipulation
// Approach: Custom sort using built-in bit count

// Time Complexity: O(n log n)
// Space Complexity: O(1) (ignoring sort internals)

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);

            if (bitsA == bitsB) {
                return a < b;
            }
            return bitsA < bitsB;
        });
        return arr;
    }
};
