// Problem Link: https://leetcode.com/problems/majority-element/
// Problem: Majority Element
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Voting Algorithm

/*
APPROACH 1: Hash Map
- Count frequency of each element
- Return element with count > n/2
Time Complexity: O(n)
Space Complexity: O(n)
*/

class SolutionHashMap {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        for (auto it : freq) {
            if (it.second > nums.size() / 2) {
                return it.first;
            }
        }
        return -1;
    }
};

/*
APPROACH 2: Boyer–Moore Voting Algorithm (Optimal)
- Maintain candidate and count
- Verify candidate
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionBoyerMoore {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
                count = 1;
            } else if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }

        int freq = 0;
        for (int x : nums) {
            if (x == candidate) freq++;
        }

        return (freq > nums.size() / 2) ? candidate : -1;
    }
};
