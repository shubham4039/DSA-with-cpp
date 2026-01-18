// Problem Link: https://leetcode.com/problems/intersection-of-two-arrays/
// Problem: Intersection of Two Arrays
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Two Pointers

/*
APPROACH 1: Sorting + Two Pointers (Optimized)
- Sort both arrays
- Use two pointers to find common unique elements
Time Complexity: O(n log n + m log m)
Space Complexity: O(1) (excluding output)
*/

class SolutionTwoPointers {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        vector<int> ans;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                if (ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            } 
            else if (nums1[i] < nums2[j]) {
                i++;
            } 
            else {
                j++;
            }
        }

        return ans;
    }
};

/*
APPROACH 2: Brute Force + Visited Array
- Check each element of nums1 in nums2
- Use visited array to avoid reuse
Time Complexity: O(n * m)
Space Complexity: O(m)
*/

class SolutionBruteForce {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> vis(nums2.size(), 0);

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j] && vis[j] == 0) {

                    bool exists = false;
                    for (int x : ans) {
                        if (x == nums1[i]) {
                            exists = true;
                            break;
                        }
                    }
                    if (exists) break;

                    ans.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
