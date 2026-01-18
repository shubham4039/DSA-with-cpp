// Problem Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Problem: Find All Duplicates in an Array
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Hashing

/*
APPROACH 1: Hash Map
- Count frequency of each element
- Add elements with frequency == 2
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int x:nums){
            mpp[x]++;
        }
        for(auto p:mpp){
            if(p.second==2){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};

/*
APPROACH 2: In-place Sign Marking (Optimal)
- Use array indices as markers
- If value at index is already negative, number is duplicate
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int ind=abs(nums[i]) - 1;
            if(nums[ind] < 0){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[ind] = -nums[ind];
            }
        }
        return ans;
    }
};