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

/////////////////////////////////// Or optimized one////////////////////////////////////////////////////////////////
bool checkIfPangram(std::string sentence) {
    if (sentence.length() < 26) {
        return false;  // Quick check: if length is less than 26, it can't be a pangram
    }

    std::vector<bool> seen(26, false);  // Track presence of each letter
    int uniqueCount = 0;  // Count of unique letters found

    for (char c : sentence) {
        int index = c - 'a';  // Convert character to alphabet index (0-25)
        if (!seen[index]) {
            seen[index] = true;
            uniqueCount++;
            if (uniqueCount == 26) {
                return true;  // All letters found, return early
            }
        }
    }

    return false;  // Not all letters were found
}
