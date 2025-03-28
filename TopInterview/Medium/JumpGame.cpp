You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.


  =========================== Brut force======================

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalindex = nums.size()-1;
        int init=0; //always start at index 0
        for(int i=1;i<nums.size()-1; ++i) { //escape 0, and last
            init+=nums[i];
        }
        return (init>=finalindex);
    }
};

But this will fail when array is [1,2] or [0,3] or [0,2,3] etc.
since we check only when size is minimum 3, or when first index will be zero than it cannot even jump.
==============================================
 ================ Final O(n)======================
 bool canJump(vector<int>& nums) {
        int scope = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > scope) return false;
            scope = max(scope, i + nums[i]);
        }
        return true;
    }

