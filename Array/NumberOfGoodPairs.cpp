// Problem Link: https://leetcode.com/problems/number-of-good-pairs/
// Problem: Number of Good Pairs
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Hashing

/*
APPROACH 1: Brute Force
- Check all pairs (i, j)
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class SolutionBruteForce {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i]==nums[j] && i<j) {
                    count++;
                }
            }
        }
        return count;
    }
};

/*
APPROACH 2: Hash Map (Single Pass)
- Count pairs while traversing
Time Complexity: O(n)
Space Complexity: O(n)
*/

class SolutionSinglePass {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int count = 0;

        for (int x : nums) {
            count += mpp[x];
            mpp[x]++;
        }
        return count;
    }
};

/*
APPROACH 3: Hash Map + Combinatorics
- For frequency f, number of pairs = f*(f-1)/2
Time Complexity: O(n)
Space Complexity: O(n)
*/

class SolutionCombinatorics {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int count = 0;

        for (int x : nums) {
            mpp[x]++;
        }

        for (auto it : mpp) {
            count += (it.second * (it.second - 1)) / 2;
        }
        return count;
    }
};
