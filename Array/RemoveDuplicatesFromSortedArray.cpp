// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Problem: Remove Duplicates from Sorted Array
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Two Pointers

/*
Approach 1: Two Pointers (Optimal)
- Since array is sorted, compare adjacent elements
- Place unique elements in the front
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};

/*
Approach 2: Hash Set
- Store unique elements using unordered_set
- Overwrite array with unique values
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;  
        int id = 0;  
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) == s.end()) { 
                s.insert(nums[i]);  
                nums[id++] = nums[i];  
            }
        }
        return s.size();  
        }
};