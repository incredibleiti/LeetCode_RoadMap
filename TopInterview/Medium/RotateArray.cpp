// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105

================== Brut force ==========================

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> copy = nums;
    
        for(int i=0; i<len; ++i) {
            int newindex = (i+k);
            if(newindex > (len-1)) {
                int add = (i + k)%len; //same as (i+k)-len (what is left is remainder)
                nums[add] = copy[i];
            } else {
                nums[newindex] = copy[i];
            }
        }        
    }

Example for algorithm brainstorming?

0--1--2--3--4--5--6
1  2  3  4  5  6  7

5  6  7  1  2  3  4

======================



6+3=9-7=2
5+3=8-7=1
4+3=7-7=0

3+3=6-7=-1

length-(oldindex + k)>0 then new index = calc
else 
newindex = oldindex + k
