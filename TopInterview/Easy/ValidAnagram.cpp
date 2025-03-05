Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

================ Brut Force ===========================
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s == t;
        
    }
};

=================== Using hashMap =======================


 class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char, int> sMap;
        for(char c: s) {
            sMap[c]++;
        }

        for(char c : t) {
            if(sMap[c]<=0) {
                return false;
            }
            sMap[c]--;
        }
        return true;
    }
};
