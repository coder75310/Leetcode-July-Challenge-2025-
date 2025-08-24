/* 2163. Minimum Difference in Sums After Removal of Elements:
You are given a 0-indexed integer array nums consisting of 3 * n elements.

You are allowed to remove any subsequence of elements of size exactly n from nums. The remaining 2 * n elements will be divided into two
equal parts:

The first n elements belonging to the first part and their sum is sumfirst.
The next n elements belonging to the second part and their sum is sumsecond.
The difference in sums of the two parts is denoted as sumfirst - sumsecond.

For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
Return the minimum difference possible between the sums of the two parts after the removal of n elements. */


class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int size = nums.size();
        
        // Step 1: Prefix sums from the left, keeping n smallest using max heap
        priority_queue<int> leftPQ;
        vector<long long> leftSum(size, 0);
        long long sumLeft = 0;

        for (int i = 0; i < 2 * n; ++i) {
            leftPQ.push(nums[i]);
            sumLeft += nums[i];
            if (leftPQ.size() > n) {
                sumLeft -= leftPQ.top();
                leftPQ.pop();
            }
            if (leftPQ.size() == n)
                leftSum[i] = sumLeft;
        }

        // Step 2: Suffix sums from the right, keeping n largest using min heap
        priority_queue<int, vector<int>, greater<int>> rightPQ;
        vector<long long> rightSum(size, 0);
        long long sumRight = 0;

        for (int i = size - 1; i >= n; --i) {
            rightPQ.push(nums[i]);
            sumRight += nums[i];
            if (rightPQ.size() > n) {
                sumRight -= rightPQ.top();
                rightPQ.pop();
            }
            if (rightPQ.size() == n)
                rightSum[i] = sumRight;
        }

        // Step 3: Find minimum difference
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, leftSum[i] - rightSum[i + 1]);
        }

        return res;
    }
};
