// Problem Link: https://leetcode.com/problems/sort-colors/
// Problem: Sort Colors
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Two Pointers

/*
APPROACH 1: Counting Method
- Count number of 0s, 1s, and 2s
- Overwrite array based on counts
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0=0, cnt1=0, cnt2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) cnt0++;
            else if(nums[i]==1) cnt1++;
            else cnt2++;
        }
        for(int i=0; i<cnt0; i++){
            nums[i]=0;
        }
        for(int i=cnt0; i<cnt0+cnt1; i++){
            nums[i]=1;
        }
        for(int i=cnt0+cnt1; i<nums.size(); i++){
            nums[i]=2;
        }
    }
};

/*
APPROACH 2: Dutch National Flag Algorithm (Optimal)
- Use three pointers: low, mid, high
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};