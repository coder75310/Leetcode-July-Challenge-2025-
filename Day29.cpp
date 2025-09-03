/* 2411. Smallest Subarrays With Maximum Bitwise OR:
You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0 to n - 1, you must determine the size of the minimum sized non-empty
subarray of nums starting at i (inclusive) that has the maximum possible bitwise OR.

In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik)
where i <= k <= n - 1.
The bitwise OR of an array is the bitwise OR of all the numbers in it.

Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum bitwise OR.

A subarray is a contiguous non-empty sequence of elements within an array. */


/* class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);
        
        vector<int> setBitIndex(32, -1);
        //setBitIndex[j] = i, it means that jth bit can be set via element at index i in nums

        for(int i = n-1; i >= 0; i--) {

            //nums[i] = binary rep
            int endIndex = i;
            for(int j = 0; j < 32; j++) {
                if(!(nums[i] & (1 << j))) { //if jth bit is not set
                    if(setBitIndex[j] != -1) {
                        endIndex = max(endIndex, setBitIndex[j]);
                    }
                } else {
                    setBitIndex[j] = i;
                }
            }

            result[i] = endIndex - i + 1;
        }

        return result;
    }
}; */





// class Solution {
//     public:
//     vector<int> smallestSubarrays(vector<int>& nums){
//         int last[32] = {};
//         for(int i=nums.size()-1; i>=0; i--){
//             int maxIndex = i;
//             for(int b=0; b<32; b++){
//                 if(nums[i] & (1<<b)){
//                     last[b] = i;
//                 } else {
//                     maxIndex = max(maxIndex, last[b]);
//                 }
//             }
//             nums[i] = maxIndex - i + 1;
//         }
//         return nums;
//     }
// };





class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastSeen(32, 0); // to store the last seen index for each bit
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 32; bit++) {
                if ((nums[i] >> bit) & 1) {
                    lastSeen[bit] = i;
                }
            }

            int maxIndex = i;
            for (int bit = 0; bit < 32; bit++) {
                maxIndex = max(maxIndex, lastSeen[bit]);
            }

            ans[i] = maxIndex - i + 1;
        }

        return ans;
    }
};
