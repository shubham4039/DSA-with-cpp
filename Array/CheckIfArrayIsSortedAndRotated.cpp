// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Problem: Check if Array Is Sorted and Rotated
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays

/*
Approach 1: Brute Force Rotation Check
- Try all rotations
- Check if any rotation results in sorted array
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool sorted;
        for(int k=0; k<n; k++){
            sorted = true;
            for(int i=0; i< n-1; i++){
                if(nums[(i+k)%n]>nums[(i+k+1)%n]){
                    sorted = false;
                    break;
                }
            }
            if(sorted) return true;
        }
        return false;
    }
};

/*
Approach 2: Optimized Count of Decreases
- Count how many times nums[i] > nums[i+1]
- For sorted rotated array, this can happen at most once
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i+1)%n])
            {
                count++;
            }
            if(count>1){
                return false;
            }
        }
        return true;
    }
};
