// Problem Link: https://leetcode.com/problems/next-permutation/
// Problem: Next Permutation
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays

/*
APPROACH 1: Using STL
- Directly use next_permutation()
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionSTL {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

/*
APPROACH 2: Manual Implementation
Steps:
1. Find the first index from right where nums[i] < nums[i+1]
2. Swap with the smallest number greater than it on the right
3. Reverse the subarray after index
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionManual {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // finding break point
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) {
                index = i;
                break;
            }
        }

        // if no break point found, reverse whole array, probably it's the last permutation
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // finding element JUST greater than nums[index]
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // reverse the suffix, i.e., elements after index
        reverse(nums.begin() + index + 1, nums.end());
    }
};
