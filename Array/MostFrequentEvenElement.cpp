// Problem Link: https://leetcode.com/problems/most-frequent-even-element/
// Problem: Most Frequent Even Element
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays / Hashing

/*
APPROACH 1: Filter + Sort
- Collect even numbers
- Sort and count frequencies
- Choose smallest element in case of tie
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> even;
        for(int it:nums){
            if(it%2==0){
                even.push_back(it);
            }
        }
        if(even.empty()) return -1;

        sort(even.begin(), even.end());

        int ans, maxi=1, cnt=1;
        ans=even[0];

        for(int i=1; i<even.size(); i++){
            if(even[i]==even[i-1]){
                cnt++;
            }
            else cnt=1;
            if(cnt>maxi){
                maxi=cnt;
                ans=even[i];
            }
        }
        return ans;

    }
};

/*
APPROACH 2: Hash Map (Single Pass, Optimal)
- Count frequencies of even numbers
- Track max frequency and smallest value on tie
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int mostfreq=-1, maxfreq=-1;
        for(int it:nums){
            if(it%2==0){
                mpp[it]++;

                if(mpp[it]>maxfreq || (mpp[it]==maxfreq && it<mostfreq)){
                    maxfreq=mpp[it];
                    mostfreq=it;

                }
                
            }
        }
        return mostfreq;
    }
};
