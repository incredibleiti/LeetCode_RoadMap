You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

I made:
class Solution {
public:
    int jump(vector<int>& nums) {
         int cnt = 1;
    int target = nums.size()-1;
    int tempsum = nums[0];
    for(int i=1; i<nums.size(); ++i) {
        if(tempsum + nums[i] >= target) {
            cnt++;
            return cnt;
        } else {
            cnt++;
        }
    }
    return cnt;
    }
};

which failed at nums = [0]


class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int end = 0;
        int farthest = 0;

        for(int i=0; i<nums.size()-1; ++i) {
            farthest = max(farthest, i+nums[i]);

            if(i == end) //reached the point of jump
            {
                jump++;
                end = farthest;
            }
        }
        return jump;
    }
};
