// Problem Link: https://leetcode.com/problems/find-peak-element/
// Problem: Find Peak Element
// Platform: LeetCode
// Difficulty: Medium
// Category: Binary Search

// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Peak element
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            // Move towards the increasing slope
            else if (nums[mid] > nums[mid - 1])
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};