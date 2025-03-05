Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true
====================== Brut Force ====================================

  bool isIsomorphic(string s, string t) {
    if(s.size()!=t.size()) return false;
    unordered_map<char,int> tMap;
    //fill in the map
    for(int i=0; i<s.size(); ++i) {
        cout << "found s[i]: " << s[i] << endl;
        if(tMap.find(s[i])==tMap.end()) {
            tMap[s[i]]=t[i];
            cout << "found s[i] value: " << t[i] << endl;
        } else {
            if(tMap[s[i]]!=t[i]) {
                 cout << "in else if not same value s[i] value: " << t[i] << endl;
                return false;
            } else {
                cout << "in else and same value s[i] value: " << t[i] << endl;
            }
        }
    }

    return true;
}
fails for:
s =
"badc"
t =
"baba"

====================== fixing both way checks ==========================

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> tMap, sMap;
        //fill in the map
        for(int i=0; i<s.size(); ++i) {
            char s1 = s[i];
            char t1 = t[i];

            if(sMap.count(s1) && sMap[s1]!=t1) return false;
            if(tMap.count(t1) && tMap[t1]!=s1) return false;
            tMap[t1]=s1;
            sMap[s1]=t1;
        }
        return true;
    }
};
