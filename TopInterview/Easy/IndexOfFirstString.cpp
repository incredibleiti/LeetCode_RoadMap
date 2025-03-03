Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.


Created solution:

int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;

    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
        int n = 0; // needle index
        
        while (n < needle.size()) {
            if( needle[n] == haystack[i + n]) { //this caused the while loop to run but never increment n if condition is not met. so infinite loop
              n++; // Move to next character
          }
        }
        
        if (n == needle.size()) {
            return i; // Full match found
        }
    }
    
    return -1; // No match found
}

==================================== Fixed the Infinite loop==============================================
  ================================== Only run while loop when condition met and increment n =============
int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;

    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
        int n = 0; // needle index
        
        while (n < needle.size() && needle[n] == haystack[i + n]) {
            n++; // Move to next character
        }
        
        if (n == needle.size()) {
            return i; // Full match found
        }
    }
    
    return -1; // No match found
}
