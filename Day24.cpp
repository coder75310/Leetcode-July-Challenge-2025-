/* 1717. Maximum Score From Removing Substrings:
You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s. */


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxStr = (x > y) ? "ab" : "ba";
        string minStr = (maxStr == "ab") ? "ba" : "ab"; //This is updated after the video was made as a new test case was added in Leetcode

        //First Pass
        string temp_first     = removeSubstring(s, maxStr);
        int L = temp_first.length();
        int removedPairsCount = (n - L) / 2;
        score                += removedPairsCount * max(x, y);


        //Second Pass
        string temp_second = removeSubstring(temp_first, minStr);
        removedPairsCount  = (L - temp_second.length()) / 2;
        score             += removedPairsCount * min(x, y);

        return score;
    }

    string removeSubstring(string& inputString, string& matchStr) {
        int i = 0;

        for (int j = 0; j < inputString.size(); j++) {
            inputString[i++] = inputString[j];

            if (i > 1 &&
                inputString[i - 2] == matchStr[0] &&
                inputString[i - 1] == matchStr[1]) {
                i -= 2;
            }
        }

        inputString.erase(inputString.begin() + i, inputString.end());

        return inputString;
    }
};
