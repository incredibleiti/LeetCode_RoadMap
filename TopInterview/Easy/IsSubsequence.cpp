Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
======================================================================================
  =========================== Brut Force ==========================================

  class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<int,int> tMap; //map for lookup
    for(int j=0; j < t.size(); ++j) {
        tMap[t[j]]=j;
        cout << "value is: " << t[j] <<" and index is: " << j << endl;
    }
    int lastindex=-1;
    for(int i=0; i<s.size(); ++i) {
        if(tMap.find(s[i])!=tMap.end()) {
            int temp = tMap[s[i]];
            cout << "found " << s[i] << " at index " << temp << endl;
            if(lastindex<i) {
                lastindex=i;
            } else {
                return false;
                break;
            }
        } else {
            return false;
            break;
        }
    }
    return true;
    }
};

Time Complexity: 
Building the unordered_map: 
O(N), where 
N is the length of t.
Iterating over s to check order: 
O(M), where 
M is the length of s.
Lookup in unordered_map: 
O(1) (on average).
Total time complexity: 
𝑂(𝑁+𝑀)
Space complexity: 
O(26) (at most 26 lowercase English letters stored) ≈ 
𝑂(1)

================= will fail since we cannot find duplicates cases =============================
  =============== we do not maintain the order of the string and this will be an issue =======

class Solution {
public:
    bool isSubsequence(string s, string t) {
     int i=0; 
    int j=0;
    while(i<s.size() && j < t.size()) {
        if(s[i]==t[j]) {
            i++;
        }
        j++;
    }
    return i == s.size();
    }
};

Time Complexity: O(n) - Linear
Space Complexity: O(1) - Constant
