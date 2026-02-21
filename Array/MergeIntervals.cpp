// Problem Link: https://leetcode.com/problems/merge-intervals/
// Problem: Merge Intervals
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Sorting / Greedy

/*
APPROACH 1: Nested Scan (Less Optimal)
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class SolutionBruteForce {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (!ans.empty() && end <= ans.back()[1]) continue;

            for (int j = i+1; j < intervals.size(); j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }

            ans.push_back({start, end});
        }
        return ans;
    }
};

/*
APPROACH 2: Optimal Greedy Merge
- Sort intervals by starting time
- Merge overlapping intervals in one pass
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class SolutionOptimal {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};

