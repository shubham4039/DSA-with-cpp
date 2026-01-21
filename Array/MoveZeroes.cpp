// Problem Link: https://leetcode.com/problems/move-zeroes/
// Problem: Move Zeroes
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Two Pointers

/*
APPROACH 1: Using Extra Array
- Store non-zero elements
- Fill remaining positions with zero
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        int nz=temp.size();
        for(int i=0; i<nz; i++){
            nums[i]=temp[i];
        }
        for(int i=nz; i<n; i++){
            nums[i]=0;
        }
        for(int i=0; i<n; i++){
            cout<<nums[i];
        }
    }
};

/*
APPROACH 2: Two Pointers (Optimal)
- Find first zero
- Swap non-zero elements forward
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j= -1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j== -1) return; 

        for(int i=j+1; i<n; i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
    }
};