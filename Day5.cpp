/* 1394. Find Lucky Integer in an Array :

Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
Return the largest lucky integer in the array. If there is no lucky integer return -1. */


class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;

        // Check for lucky numbers
        for (auto& pair : freq) {
            int num = pair.first;
            int count = pair.second;

            if (num == count) {
                result = max(result, num);
            }
        }

        return result;
    }
};
