// Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Problem: Minimum Number of Days to Make m Bouquets
// Platform: LeetCode
// Difficulty: Medium
// Category: Binary Search / Binary Search on Answer

// Time Complexity: O(n log(maxDay))
// Space Complexity: O(1)

class Solution {
public:

    int bouquetsPossible(vector<int>& bloomDay, int day, int k) {

        int bouquets = 0;
        int flowers = 0;

        for (int x : bloomDay) {

            if (x <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } 
            else {
                flowers = 0;
            }
        }

        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long required = (long long)m * k;
        if (required > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (bouquetsPossible(bloomDay, mid, k) >= m) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};