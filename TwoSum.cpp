// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]


Brut force/////////////////////////////////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
    for(int i=0; i< nums.size(); ++i) {
        for (int j=i+1; j < nums.size(); ++j) {
            if(nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
            }

        }
    }
    return res;
    }
};

======================= Time complexity=======================
Inner loop and outer loop in worst case run O(N) so twice loop O(N^2)
Space is extra array = O(1) //onl storing indices

/////////////////////// Solution 2////////////////////////////////////////////////////////
////////// Avoiding double loop////////////////////////////////////

vector<int> twoSum(vector<int>& nums, int target) {

    vector<int> res;   
    int index = 0;
    int val = nums[index];
    for(int i=1; i< nums.size(); ++i) {
        if((target - nums[i]) == val) {
            res.push_back(index);
            res.push_back(i);
            break;
        } else {
            index = i;
            val = nums[i];
        }
    }
    return res;
        
}
======================= Time complexity=======================
One loop so time complexity is O(N) -> worst case and best case O(1)
Space is extra array = O(1) //onl storing indices

