// Problem Link: https://leetcode.com/problems/search-insert-position/
// Problem: Search Insert Position
// Platform: LeetCode
// Difficulty: Easy
// Category: Binary Search
// Concept: Lower Bound

// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;  
    }
};