Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

===================== Brut Force =================================
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         int l = 0;
    int r = 0;
    
    while(l<ransomNote.size()) {
        if(ransomNote[l] == magazine[r]) {
            l++;
            r++;
        } else {
            return false;
        }
    }
    return l == ransomNote.size();
    }
};

//Failed for ransom "aab" and magazine "baa"

========================== Using HashMaps==========================

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magazineHashMap;
    //fill in the map
    for(char c : magazine) {
        magazineHashMap[c]++;
    }
    
    //loop over string and now deduct the instance from map values
    for(char c : ransomNote) {
        if(magazineHashMap[c] <=0){
            return false;
        }
        magazineHashMap[c]--;
    }
    
    return true;
    }
};
  
