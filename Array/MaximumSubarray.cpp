// Problem Link: https://leetcode.com/problems/maximum-subarray/
// Problem: Maximum Subarray
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Dynamic Programming

/*
APPROACH 1: Kadane’s Algorithm (Classic)
- Reset running sum when it becomes negative
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionKadaneClassic {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            currSum += x;
            maxSum = max(maxSum, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};
