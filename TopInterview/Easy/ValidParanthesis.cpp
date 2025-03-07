Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.



class Solution {
public:
    bool isValid(string s) {
        //closing bracket is the 'key', which means when key is searched and value is found (open bracket), so validate
        //if the stack top open and value of key match (pop it out)
        stack<char> st;
        unordered_map<char,char> charMap = {{')', '('}, {']', '['}, {'}', '{'}}; 
        for(char c:s) {
            if(charMap.find(c)==charMap.end()) { // search and key doesnt exits, means its a opening bracket
                st.push(c);
            } else if(st.top() == charMap[c]) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
