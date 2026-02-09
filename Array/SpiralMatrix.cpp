// Problem Link: https://leetcode.com/problems/spiral-matrix/
// Problem: Spiral Matrix
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Matrix
// Approach: Boundary traversal (top, right, bottom, left)

// Time Complexity: O(n * m)
// Space Complexity: O(1) (excluding output)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;

        while(top <= bottom && left <= right){
            for(int j=left; j<=right; j++){
                ans.push_back(matrix[top][j]);
            }
            top++;
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
                for(int j=right; j>=left; j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};