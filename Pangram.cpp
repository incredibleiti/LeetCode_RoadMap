// 1832. Check if the Sentence Is Pangram
// Easy
// Topics
// Companies
// Hint
// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

 

// Example 1:

// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.
// Example 2:

// Input: sentence = "leetcode"
// Output: false
 

// Constraints:

// 1 <= sentence.length <= 1000
// sentence consists of lowercase English letters.

Brut force will be:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool result = true;
        int nsize = sentence.length();
        if(nsize < 26) {
            return false;
        } else {
            string alphabets = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i <nsize ; ++i){
                if (alphabets.find(sentence[i]) == string::npos) {
                result = false;
            }
            }
        }
        return result;
    }
};
