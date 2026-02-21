// Problem Link: https://leetcode.com/problems/reverse-pairs/
// Problem: Reverse Pairs
// Platform: LeetCode
// Difficulty: Hard
// Category: Arrays / Divide and Conquer / Merge Sort

/*
APPROACH: Modified Merge Sort
- Use merge sort to divide array
- Count pairs before merging
- Condition: arr[i] > 2 * arr[j]
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i-low];
        }
    }

    long long countPairs(vector<int> &arr, int low, int mid, int high) {
        long long cnt = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && 
                  (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            cnt += (right-(mid+1));
        }
        return cnt;
    }

    long long mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        long long cnt = 0;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};