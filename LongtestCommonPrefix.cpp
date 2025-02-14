/* 14. Longest Common Prefix
Easy
Topics
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty. 
*/

///////////////////////// Longest Brut Force for checking Vertically////////////////////////////////////////////////////////////////


#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    int prefixLength = 0; // Track prefix length instead of using substr()

    for (int i = 0; i < strs[0].size(); i++) {
        char c = strs[0][i]; // Pick character from first string

        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, prefixLength); // Stop at mismatch
            }
        }

        prefixLength++; // Only increment when all strings match at this index
    }

    return strs[0]; // If fully matched, return first string
}


// Main function to test Singleton
int main() {
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};

    cout << "Longest Common Prefix: " << longestCommonPrefix(strs1) << endl;
    cout << "Longest Common Prefix: " << longestCommonPrefix(strs2) << endl;

    return 0;
}
