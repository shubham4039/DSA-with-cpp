// Problem Link: https://leetcode.com/problems/missing-number/
// Problem: Missing Number
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Bit Manipulation

/*
APPROACH 1: Sum Formula
- Sum of first n natural numbers = n*(n+1)/2
- Subtract array sum to get missing number
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum;
        sum=n*(n+1)/2;
        int s2=0;
        for(int i=0; i<n; i++){
            s2+=nums[i];
        }
        return (sum-s2);
    }
};
/*
APPROACH 2: XOR Method
- XOR of all numbers from 0 to n
- XOR with array elements
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1=0, xor2=0;
        
        for(int i=0; i<n; i++){
            xor2=xor2^nums[i];
            xor1=xor1^i;
        }
        xor1=xor1^n;
        return xor1^xor2;
    }
};