/* 3304. Find the K-th Character in String Game I :
Alice and Bob are playing a game. Initially, Alice has a string word = "a".
You are given a positive integer k.
Now Bob will ask Alice to perform the following operation forever:
Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word, after enough operations have been done for word to have at least k characters. */


class Solution {
public:  //////
    char kthCharacter(int k) {
        int step = 0;
        int length = 1;
        while (length < k) {
            length *= 2;
            step++;
        }
        
        int add = 0; // How many times we applied "next character"
        
        while (step > 0) {
            int half = length / 2;
            if (k > half) {
                // k is in second half: corresponds to (k - half)-th character in previous step,
                // but this character is shifted by +1 (next character)
                k -= half;
                add++;
            }
            // else: k is in first half, no change
            
            length = half;
            step--;
        }
        
        // Initially character was 'a' → value 0
        int final_char = (0 + add) % 26;
        return 'a' + final_char;
    }
};
