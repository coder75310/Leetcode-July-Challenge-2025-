/* 3307. Find the K-th Character in String Game II :

Alice and Bob are playing a game. Initially, Alice has a string word = "a".
You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.
Now Bob will ask Alice to perform all operations in sequence:
If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation. */


class Solution {
public:     // public
    char kthCharacter(long long k, vector<int>& operations) {
        vector<int> trimmedOps;
        long long curr_len = 1;

        // Only keep operations while total length < k
        for (int op : operations) {
            if (curr_len >= k) break;
            trimmedOps.push_back(op);
            curr_len *= 2;
        }

        // Now process in reverse
        string base = "a";
        for (int i = trimmedOps.size() - 1; i >= 0; --i) {
            long long half = curr_len / 2;
            if (k > half) {
                k -= half;
                if (trimmedOps[i] == 1) {
                    base = increment(base);
                }
            }
            curr_len = half;
        }

        return base[k - 1];
    }

private:   // private
    string increment(const string& s) {
        string res;
        for (char c : s) {
            if (c == 'z') res += 'a';
            else res += c + 1;
        }
        return res;
    }
};
