/* 898. Bitwise ORs of Subarrays:
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array. */


// Method : 1
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        for(int i=0; i<arr.size(); i++){
            for(const int& x : prev){
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};


// Method : 2
/* class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for(int num : arr){
            unordered_set<int> curr;
            curr.insert(num);
            for(int val : prev){
                curr.insert(val | num);
            }
            result.insert(curr.begin(), curr.end());
            prev = curr;
        }

        return result.size();
    }
}; */


// Method : 3
/* class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result, current;

        for(int num : arr){
            unordered_set<int> next;
            next.insert(num);
            for(int val : current){
                next.insert(val | num);
            }
            current = next;
            result.insert(current.begin(), current.end());
        }

        return result.size();
    }
};
 */
