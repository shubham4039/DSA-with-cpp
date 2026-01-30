// Problem Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
// Problem: Replace Elements with Greatest Element on Right Side
// Platform: LeetCode
// Difficulty: Easy
// Category: Arrays

/*
APPROACH 1: Brute Force
- For each element, scan all elements to its right
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr){
        int n = arr.size();
        for(int i=0; i<n; i++){
            int maxi = -1;
            for(int j=i+1; j<n; j++){
                if(arr[j]>maxi){
                    maxi = arr[j];
                }
            }
            arr[i] = maxi; 
        }
        return arr;
    }
};

/*
APPROACH 2: Optimal (Traverse from Right)
- Maintain maximum element seen so far from the right
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr){
        int n = arr.size();
        int maxi = -1;
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            arr[i] = maxi;
            maxi = max(maxi, curr);
        }
        return arr;
    }
};
