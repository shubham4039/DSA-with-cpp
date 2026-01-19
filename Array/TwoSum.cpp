// Problem Link: https://leetcode.com/problems/two-sum/
// Problem: Two Sum
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays

/*
APPROACH 1: Brute Force
- Check all pairs
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

/*
APPROACH 2: Sorting + Two Pointers
- Store value with original index
- Sort and use two pointers
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(),arr.end());
        int left = 0, right = arr.size()-1;
        while(left<right){
            int sum = arr[left].first + arr[right].first;
            if(sum==target){
                return{arr[left].second, arr[right].second};
            }                                     
            else if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return{-1,-1};
    }
};
