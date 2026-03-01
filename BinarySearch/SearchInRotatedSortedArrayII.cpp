// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Problem: Search in Rotated Sorted Array II
// Platform: LeetCode
// Difficulty: Medium
// Category: Binary Search
// Concept: Modified Binary Search with Duplicates

// Time Complexity: O(log n) average, O(n) worst case
// Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                return true;
            }
            // If we have duplicates, we can just skip them
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++, high--;
                continue;
            }
            //Left half is sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //Right half is sorted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};