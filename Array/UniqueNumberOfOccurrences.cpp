// Problem Link: https://leetcode.com/problems/unique-number-of-occurrences/
// Problem: Unique Number of Occurrences
// Platform: LeetCode
// Difficulty: Easy
// Category: Hashing / Arrays

/*
APPROACH 1: Sorting
- Sort array
- Count frequencies
- Store counts in vector
- Check for duplicates after sorting counts
Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class SolutionSorting {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> freq;

        for (int i = 0; i < arr.size(); i++) {
            int cnt = 1;
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                cnt++;
                i++;
            }
            freq.push_back(cnt);
        }

        sort(freq.begin(), freq.end());
        for (int i = 1; i < freq.size(); i++) {
            if (freq[i] == freq[i - 1]) {
                return false;
            }
        }
        return true;
    }
};

/*
APPROACH 2: HashMap + Set
- Count frequencies using unordered_map
- Insert frequencies into unordered_set
- Compare sizes
Time Complexity: O(n)
Space Complexity: O(n)
*/

class SolutionHashing {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        for (int x : arr) {
            mpp[x]++;
        }

        unordered_set<int> st;
        for (auto it : mpp) {
            st.insert(it.second);
        }

        return mpp.size() == st.size();
    }
};
