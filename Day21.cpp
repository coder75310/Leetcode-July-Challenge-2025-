/* 1957. Delete Characters to Make Fancy String :
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique. */


/* class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int frequency = 1;
        string ans = "";
        ans.push_back(s[0]);

        for(int i=1; i < s.size(); i++){
            if(s[i] == prev){
                frequency++;
            } else {
                prev = s[i];
                frequency = 1;
            }

            if(frequency < 3) ans.push_back(s[i]);
        }
        
        return ans;
    }
}; */




class Solution {
public:
    string makeFancyString(string s) {
        string result;
        for (char c : s) {
            int n = result.size();
            // Check last two characters in the result
            if (n >= 2 && result[n - 1] == c && result[n - 2] == c) {
                continue; // skip adding c
            }
            result += c;
        }
        return result;
    }
};
