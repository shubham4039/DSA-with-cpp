// Problem Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Problem: Rearrange Array Elements by Sign
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays

/*
APPROACH 1: Separate Positives and Negatives
- Store positives and negatives in separate arrays
- Place them alternately
Time Complexity: O(n)
Space Complexity: O(n)
*/

class SolutionSeparateArrays {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        for (int x : nums) {
            if (x >= 0) pos.push_back(x);
            else neg.push_back(x);
        }

        for (int i = 0; i<nums.size() / 2; i++) {
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        return nums;
    }
};

/*
APPROACH 2: Direct Index Placement (Cleaner)
- Place positives at even indices
- Place negatives at odd indices
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0, neg=1;
        vector<int> ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};
