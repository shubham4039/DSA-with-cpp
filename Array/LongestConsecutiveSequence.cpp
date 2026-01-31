// Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Problem: Longest Consecutive Sequence
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Hashing
// Approach: Use unordered_set to check sequence starts

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;
        for(int it : s){
            if(s.find(it-1)==s.end()){
                int current = it;
                int cnt = 1;
                while(s.find(current+1)!=s.end()){
                    current++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};