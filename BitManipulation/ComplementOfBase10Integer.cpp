// Problem Link: https://leetcode.com/problems/complement-of-base-10-integer/
// Problem: Complement of Base 10 Integer
// Platform: LeetCode
// Difficulty: Easy
// Approach: Create bitmask and apply bitwise NOT
// Time Complexity: O(log2(n))
// Space Complexity: O(1)

class Solution {
public:
    int bitwiseComplement(int n){
        int a=0, m=n ;
        if(n==0) return 1;
        while(m!=0){
            a=(a<<1)|1;
            m=m>>1;
        }
        int ans = (a&(~n));
        return ans;
    }
};
