// Problem Link: https://leetcode.com/problems/remove-element/
// Problem: Remove Element
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Two Pointers

/*
APPROACH 1: Shifting Elements (Brute Force)
- When target found, shift remaining elements left
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class SolutionShifting {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                n--;
                i--; 
            }
        }
        return n;
    }
};

/*
APPROACH 2: Two Pointers (Optimal)
- Overwrite unwanted elements
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionTwoPointers {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
