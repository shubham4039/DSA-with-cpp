// Problem Link: https://leetcode.com/problems/contains-duplicate/
// Problem: Contains Duplicate
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Hashing / Sorting

/*
APPROACH 1: Hash Map
Count frequency of elements
If any frequency > 1 → duplicate exists
Time Complexity: O(n)
Space Complexity: O(n)
*/

class SolutionHashing {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int it: nums) {
            freq[it]++;
            if (freq[it] > 1) {
                return true;
            }
        }
        return false;
    }
};

/*
APPROACH 2: Sorting
Sort array
Check adjacent elements
Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class SolutionSorting {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};
