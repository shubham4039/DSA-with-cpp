// Problem Link: https://leetcode.com/problems/binary-search/
// Problem: Binary Search
// Platform: LeetCode
// Difficulty: Easy
// Category: Binary Search

/*
APPROACH 1: Iterative Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};

/*
APPROACH 2: Recursive Binary Search
Time Complexity: O(log n)
Space Complexity: O(log n) (recursion stack)
*/

class Solution {
public:
    int binarySearch(vector<int> &nums, int low, int high, int target){
        if(low>high) return -1;
        int mid = (low+high)/2;

        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return binarySearch(nums, mid+1, high, target);
        return binarySearch(nums, low, mid-1, target);
    }
    int search(vector<int>& nums, int target){
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};