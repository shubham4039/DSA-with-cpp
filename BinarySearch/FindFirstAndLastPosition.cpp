// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Problem: Find First and Last Position of Element in Sorted Array
// Platform: LeetCode
// Difficulty: Medium
// Category: Binary Search

/*
APPROACH 1: Separate First and Last Position Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int firstPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int lastPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return { firstPos(nums, target), lastPos(nums, target) };
    }
};

/*
APPROACH 2: Using Lower Bound and Upper Bound
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lowerBound(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1, ans=n;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    int upperBound(vector<int>& nums, int target){
        int n=nums.size();
        int low=0, high=n-1, ans=n;
        while(low<=high){
            int mid= low+ (high-low)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lowerBound(nums, target);
        if(lb == nums.size() || nums[lb] != target) return{-1,-1};
        return{lowerBound(nums, target), upperBound(nums, target)-1};
    }
};