/* 3202. Find the Maximum Length of Valid Subsequence II :
You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
Return the length of the longest valid subsequence of nums. */


class Solution {
public:
//
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n); // dp[i][mod] = max length ending at i with mod
        int result = 1; // min valid subsequence has at least length 1

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;
                int prevLen = dp[j].count(mod) ? dp[j][mod] : 1;
                dp[i][mod] = max(dp[i][mod], prevLen + 1);
                result = max(result, dp[i][mod]);
            }
        }

        return result;
    }
};
