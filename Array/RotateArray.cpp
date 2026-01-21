// Problem Link: https://leetcode.com/problems/rotate-array/
// Problem: Rotate Array
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays

/*
APPROACH 1: Extra Array
- Create a temporary array
- Place elements at (i + k) % n
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> arr(n);

        for(int i=0; i<n; i++){
            arr[(i+k)%n]=nums[i];
        }
        nums = arr ;
    }
};

/*
APPROACH 2: Reversal Algorithm (Optimal)
- Reverse whole array
- Reverse first k elements
- Reverse remaining elements
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionOptimal {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
