Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

===================================================================================================================
  ===============================================================================================================

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> numsMap;
        for(int i=0;i<nums.size(); ++i) {           
            if(numsMap.find(nums[i])!=numsMap.end()) {
                if((i-numsMap[nums[i]])<=k) {
                    return true;
                } 
            }
            numsMap[nums[i]]=i; //key and index
        }
        return false;
    }
};
