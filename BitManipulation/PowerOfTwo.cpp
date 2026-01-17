// Problem Link: https://leetcode.com/problems/power-of-two/
// Problem: Power of Two
// Platform: LeetCode
// Difficulty: Easy
// Approach: Check if only one set bit exists using (n & (n - 1))
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 && (n&(n-1))==0){
            return true;
        }
        else{
            return false;
        }
    }
};