// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

================= Brut force ======================================

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> numsMap;
        for(int i =0; i< nums.size(); ++i) {
            numsMap[nums[i]]+=1;
            if(numsMap[nums[i]] > nums.size()/2) return nums[i];
        }
        return 0;       
    }
};
