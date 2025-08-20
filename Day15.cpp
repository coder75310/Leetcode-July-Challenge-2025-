/* 3136. Valid Word :
A word is considered valid if:

It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.
You are given a string word.

Return true if word is valid, otherwise, return false. */


class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        string vowels = "aeiouAEIOU";

        for (char c : word) {
            if (!isalnum(c)) {
                // contains character other than digit or English letter
                return false;
            }
            if (isalpha(c)) {
                if (vowels.find(c) != string::npos) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};  
