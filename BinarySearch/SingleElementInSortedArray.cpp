// Problem Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Problem: Single Element in a Sorted Array
// Platform: LeetCode
// Difficulty: Medium
// Category: Binary Search

// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //Edge cases
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low=1, high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            //Check if mid is the unique element
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            //Decide the search side based on index parity
            if(((mid%2==0) && nums[mid]==nums[mid+1]) || ((mid%2==1) && nums[mid]==nums[mid-1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};