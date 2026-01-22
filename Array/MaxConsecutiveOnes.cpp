// Problem Link: https://leetcode.com/problems/max-consecutive-ones/
// Problem: Max Consecutive Ones
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays
// Approach: Single pass counting consecutive ones
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, maxi=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=0;
            }
        }
        return maxi;
    }
};
