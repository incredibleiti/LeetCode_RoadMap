Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

==================== Brut Force =======================
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,int> strsMap;
        for(int i=0; i< strs.size(); ++i) {
            if(!strsMap.count(strs[i])) {
                vector<string> insidevector;            
                insidevector.push_back(strs[i]);
                string temp = strs[i];         
                for(int j=i+1; j<strs.size(); ++j) {
                    sort(temp.begin(), temp.end());
                    string temp1 = strs[j];
                    sort(temp1.begin(), temp1.end());
                    if(temp==temp1) {
                        insidevector.push_back(strs[j]);
                        strsMap[strs[j]]=1;
                    }
                }
                result.push_back(insidevector);
            } else {
                strsMap[strs[i]]=1;
            }
        }
        return result;
        
    }


TimeComplexity
1. Outer Loop (for i=0 to strs.size())

for(int i=0; i< strs.size(); ++i) {
This runs N times, where N = strs.size().
  
2. Sorting Inside the Loop
Inside the outer loop, you are sorting temp and temp1:
sort(temp.begin(), temp.end());
sort(temp1.begin(), temp1.end());
Sorting a string of length K takes O(K log K).

3. Inner Loop (for j=i+1 to strs.size())
for(int j=i+1; j<strs.size(); ++j) {
In the worst case, this inner loop runs (N-1) + (N-2) + ... + 1 = O(N²) times.
Inside the inner loop, the most expensive operation is sorting each word.
Total Complexity Calculation
Outer Loop (i): Runs O(N) times.
Inner Loop (j): Runs O(N²) in the worst case.
Sorting Each Word (O(K log K)): Happens inside the inner loop.
Thus, the overall complexity is:

𝑂(𝑁2 𝐾log𝐾)
=========================Using HashMaps====================================
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> strsMap;
        for(int i=0; i< strs.size(); ++i) {
            string _sorttemp = strs[i]; //make a copy
            sort(_sorttemp.begin(), _sorttemp.end());
            strsMap[_sorttemp].push_back(strs[i]);
        }

        for(auto val: strsMap) {
            result.push_back(val.second);
        }
        return result;
    }
O(N K log K)

