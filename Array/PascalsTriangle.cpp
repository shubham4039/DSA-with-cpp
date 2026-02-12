// Problem Link: https://leetcode.com/problems/pascals-triangle/
// Problem: Pascal’s Triangle
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Dynamic Programming / Combinatorics

/*
APPROACH 1: Using nCr Formula
- Compute each row using combination formula
Time Complexity: O(n^2)
Space Complexity: O(1) extra (excluding output)
*/

class SolutionCombinatorics {
public:
    vector<int> generateRow(int row) {
        long long val = 1;
        vector<int> result;
        result.push_back(1);

        for (int col = 1; col < row; col++) {
            val = val * (row - col);
            val = val / col;
            result.push_back(val);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++) {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

/*
APPROACH 2: Build Using Previous Row (Using separate prevRow)
Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class SolutionUsingPrevRow {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prevRow;

        for (int i = 0; i < numRows; i++) {
            vector<int> currRow(i + 1, 1);

            for (int j = 1; j < i; j++) {
                currRow[j] = prevRow[j - 1] + prevRow[j];
            }

            ans.push_back(currRow);
            prevRow = currRow;
        }
        return ans;
    }
};

/*
APPROACH 3: Directly Use ans[i-1]
Time Complexity: O(n^2)
Space Complexity: O(1) extra (excluding output)
*/

class SolutionDirectDP {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(row);
        }
        return ans;
    }
};
