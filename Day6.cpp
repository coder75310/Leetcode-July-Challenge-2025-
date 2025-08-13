/* 1865. Finding Pairs With a Certain Sum :

You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:
Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).

Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot. */


class FindSumPairs {
public: ////////
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        int newVal = oldVal + val;
        freq2[oldVal]--;
        if (freq2[oldVal] == 0) {
            freq2.erase(oldVal);  // optional, keeps map smaller
        }
        freq2[newVal]++;
        nums2[index] = newVal;
    }

    int count(int tot) {
        int result = 0;
        for (int a : nums1) {
            int b = tot - a;
            if (freq2.find(b) != freq2.end()) {
                result += freq2[b];
            }
        }
        return result;
    }
};
