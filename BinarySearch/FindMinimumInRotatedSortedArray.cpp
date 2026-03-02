// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Problem: Find Minimum in Rotated Sorted Array
// Platform: LeetCode
// Difficulty: Medium
// Category: Binary Search

// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Otherwise right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};