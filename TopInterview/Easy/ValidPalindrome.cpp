A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

class Solution {
public:
    bool isPalindrome(string s) {
        string newstr="";
        bool result = false;
        for(char c: s) {
            if(isalnum(c)) {
                newstr+=tolower(c);
            }
        }
        return newstr == string(newstr.rbegin(), newstr.rend());
    }
};
