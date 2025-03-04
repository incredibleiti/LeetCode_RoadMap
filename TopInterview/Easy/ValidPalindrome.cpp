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

Time and Space Complexity Analysis
Time Complexity
The algorithm iterates over the input string s once to construct newstr, which takes O(n) time.
Then, it creates a reversed copy of newstr using string(newstr.rbegin(), newstr.rend()), which also takes O(n) time.
Finally, the comparison between newstr and its reverse takes O(n) in the worst case.
Thus, the overall time complexity is O(n).

Space Complexity
The newstr variable stores a filtered version of the original string, which can be at most O(n) in size.
The reverse function also creates an additional copy of newstr, leading to another O(n) space usage.
Therefore, the space complexity is O(n).
