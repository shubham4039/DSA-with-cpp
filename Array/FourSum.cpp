// Problem Link: https://leetcode.com/problems/4sum/
// Problem: 4Sum
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Two Pointers / Hashing

/*
APPROACH 1: Brute Force + Hashing + Set
- Fix first two elements
- Use hashing for the third and fourth
Time Complexity: O(n^3 log n)
Space Complexity: O(n)
*/

class SolutionHashing {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                set<long long> hashset;

                for (int k = j + 1; k < nums.size(); k++) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum;

                    if (hashset.find(fourth) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

/*
APPROACH 2: Sorting + Two Pointers (Optimal)
- Fix first two elements
- Use two pointers for remaining two
Time Complexity: O(n^3)
Space Complexity: O(1) (excluding output)
*/

class SolutionOptimal {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
