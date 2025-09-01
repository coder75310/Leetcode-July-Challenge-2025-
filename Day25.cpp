/* Q25:

Code
3487. Maximum Unique Subarray Sum After Deletion:
You are given an integer array nums.

You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:

All elements in the subarray are unique.
The sum of the elements in the subarray is maximized.
Return the maximum sum of such a subarray. */


// Method 1
/* class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        // vector<int> st(101, -1);

        int sum = 0;

        int maxNeg = INT_MIN;
        
        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(!st.count(num)) {
                sum += num;
                st.insert(num);
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
};
 */





// Method 2
class Solution {
public:
    int maxSum(vector<int>& nums) {
        // unordered_set<int> st;
        vector<int> st(101, -1);

        int sum = 0;

        int maxNeg = INT_MIN;

        for(int &num : nums) {
            if(num <= 0) {
                maxNeg = max(maxNeg, num);
            } else if(st[num] == -1) {
                sum += num;
                // st.insert(num);
                st[num] = 1;
            }
        }
        
        return sum == 0 ? maxNeg : sum;
    }
};

