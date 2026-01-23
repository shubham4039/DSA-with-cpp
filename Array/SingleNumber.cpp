// Problem Link: https://leetcode.com/problems/single-number/
// Problem: Single Number
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Bit Manipulation

/*
APPROACH 1: Brute Force
- Count frequency of each element
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums){
        int n=nums.size();
        int digit, count;
        for(int i=0; i<n; i++){
            digit=nums[i];
            count=0;
            for(int j=0; j<n; j++){
                if(digit==nums[j]){
                    count++;
                }
            }
            if(count==1){
                return digit;
            }
        }
        return -1;
    }
};

/*
APPROACH 2: XOR (Optimal)
- XOR of same numbers cancels out
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums){
        int n=nums.size();
        int XOR=0;
        for(int i=0; i<n; i++){
            XOR=XOR^nums[i];
        }
        return XOR;
    }
};