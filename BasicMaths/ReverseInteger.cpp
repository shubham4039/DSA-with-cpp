//Problem link: https://leetcode.com/problems/reverse-integer/
// Problem: Reverse Integer
// Platform: LeetCode
// Difficulty: Medium
// Approach: Digit extraction and overflow check
// Time Complexity: O(log10(n))
// Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int rem = x % 10;

            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }
            rev = rev * 10 + rem;
            x /= 10;
        }
        return rev;
    }
};