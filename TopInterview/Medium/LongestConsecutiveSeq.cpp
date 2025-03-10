128. Longest Consecutive Sequence
Attempted
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3

Mde this:

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        long longseq {0};
        long currseq {1};

        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); ++i) {
            if(nums[i]-nums[i-1] == 1) {
                currseq+=1;
            } else if(nums[i] == nums[i-1]) {
                currseq=currseq; //keep the counter
            }
            else {
                if(longseq<currseq) longseq = currseq; 
                currseq = 1; ///reset
            }
        }
        
        if(longseq<currseq) longseq = currseq; 
        return longseq;
    }
};
==================== Time complexity is O(nlog n)
