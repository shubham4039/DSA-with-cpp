// Problem Link: https://leetcode.com/problems/majority-element-ii/
// Problem: Majority Element II
// Platform: LeetCode
// Difficulty: Medium
// Category: Arrays / Hashing / Voting Algorithm

/*
APPROACH 1: Brute Force
- Count frequency for each unique element
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class SolutionBruteForce {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            bool alreadyTaken = false;
            for (int x : result) {
                if (x == nums[i]) {
                    alreadyTaken = true;
                    break;
                }
            }
            if (alreadyTaken) continue;

            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i]) count++;
            }

            if (count > nums.size() / 3) {
                result.push_back(nums[i]);
            }
            if (result.size() == 2) break;
        }
        sort(result.begin(), result.end());
        return result;
    }
};

/*
APPROACH 2: Hash Map
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ls;
        unordered_map<int, int> mpp;
        int mini = (nums.size()/3)+1;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==mini){
                ls.push_back(nums[i]);
            }
            if(ls.size()==2) break;
        }
        sort(ls.begin(), ls.end());
        return ls;  
    }
};

/*
APPROACH 3: Extended Boyer–Moore Voting Algorithm (Optimal)
Time Complexity: O(n)
Space Complexity: O(1)
*/

class SolutionOptimal {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;

        //Finding candidates
        for (int x : nums) {
            if (candidate1 == x) {
                count1++;
            }
            else if (candidate2 == x) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        //Verifying candidates
        count1 = count2 = 0;
        for (int x : nums) {
            if (x == candidate1) count1++;
            else if (x == candidate2) count2++;
        }

        vector<int> result;
        int threshold = nums.size() / 3;

        if (count1 > threshold) result.push_back(candidate1);
        if (count2 > threshold) result.push_back(candidate2);

        sort(result.begin(), result.end());
        return result;
    }
};
