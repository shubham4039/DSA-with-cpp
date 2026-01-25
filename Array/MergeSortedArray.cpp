// Problem Link: https://leetcode.com/problems/merge-sorted-array/
// Problem: Merge Sorted Array
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Two Pointers

/*
APPROACH 1: Extra Array
- Merge both arrays into a temporary array
- Copy result back to nums1
Time Complexity: O(m + n)
Space Complexity: O(m + n)
*/

class SolutionExtraArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                temp.push_back(nums1[i++]);
            } else {
                temp.push_back(nums2[j++]);
            }
        }

        while (i < m) temp.push_back(nums1[i++]);
        while (j < n) temp.push_back(nums2[j++]);

        nums1.assign(temp.begin(), temp.end());
    }
};

/*
APPROACH 2: In-place Merge from Back (Optimal)
- Start merging from the end to avoid overwriting nums1
Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class SolutionInPlace {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
