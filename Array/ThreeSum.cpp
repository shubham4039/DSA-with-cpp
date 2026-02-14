// Problem Link: https://leetcode.com/problems/3sum/
// Problem: 3Sum
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Two Pointers / Hashing

/*
APPROACH 1: Hashing + Set
- Fix one element
- Use set to detect remaining two elements
Time Complexity: O(n^2 log n)
Space Complexity: O(n)
*/

class SolutionHashing {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            set<int> seen;
            for (int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]);

                if (seen.find(third) != seen.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                seen.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};

/*
APPROACH 2: Sorting + Two Pointers (Optimal)
- Sort array
- Fix one element
- Use two pointers for remaining two
Time Complexity: O(n^2)
Space Complexity: O(1) (excluding output)
*/

class SolutionOptimal {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return ans;
    }
};
