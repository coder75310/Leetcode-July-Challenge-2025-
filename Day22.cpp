/* 1695. Maximum Erasure Value :
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r). */


// Method: 1   /// 
/* class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        int i=0;
        int j=0;
        int sum = 0;
        int result = 0;

        while(j < n){
            if(!st.count(nums[j])){
                sum += nums[j];
                result = max(result, sum);
                st.insert(nums[j]);
                j++;
            } else { // we have seen this nums[j]. So time to shrink the window
                while(st.count(nums[j])){
                    sum -= nums[i];
                    st.erase(nums[i]);  // O(1)
                    i++;
                }

            }
        }

        return result;
    }
}; */




// Method:- 2
/* class Solution {
    public:
    int maximumUniqueSubarray(vector<int>& nums){
        int n = nums.size();

        vector<int> cumSum(n, 0);
        cumSum[0] = nums[0];
        for(int i=1; i<n; i++){
            cumSum[i] = cumSum[i-1] + nums[i];
        }

        vector<int> mp(10001, -1);
            int result = 0;
            int i=0;
            int j=0;

            while(j<n){
                i = max(i, mp[nums[j]]+1);    // jumping i so that i to j is valid
                // subarray sum of i to j
                int jthSum = cumSum[j];
                int ithSum = i-1 < 0 ? 0 : cumSum[i-1];

                result = max(result, jthSum - ithSum);

                mp[nums[j]] = j;
                j++;
            }

            return result;
    }
}; */







class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int currSum = 0, maxSum = 0;

        while (right < nums.size()) {
            // If nums[right] is not in the set, expand window
            if (seen.find(nums[right]) == seen.end()) {
                seen.insert(nums[right]);
                currSum += nums[right];
                maxSum = max(maxSum, currSum);
                right++;
            } 
            // Else, remove from the left until nums[right] can be inserted
            else {
                seen.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
        }

        return maxSum;
    }
};
