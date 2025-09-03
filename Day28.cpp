/* 2044. Count Number of Maximum Bitwise-OR Subsets:
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements
chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed). */


class Solution {
public:
    //O(2^n)
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr) {
        if(idx == nums.size()) {
            if(currOr == maxOr)
                return 1; //Found one subset
            return 0;
        }

        //Take nums[idx]
        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);

        //Not taken nums[idx]
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr);


        return takeCount + notTakeCount;

    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums) {
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr);
    }
};
