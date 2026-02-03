// Problem Link: https://leetcode.com/problems/rotate-image/
// Problem: Rotate Image
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Matrix

/*
APPROACH 1: Extra Matrix
- Create a new matrix
- Place element at rotated position
Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class SolutionExtraSpace {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j][n-1-i] = matrix[i][j];
            }
        }
        matrix = temp;
    }
};

/*
APPROACH 2: In-Place (Transpose + Reverse)
Steps:
1. Transpose the matrix
2. Reverse each row
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
