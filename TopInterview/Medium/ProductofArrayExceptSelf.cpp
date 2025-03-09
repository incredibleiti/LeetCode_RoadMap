Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

================ Brut force =======================
  class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> result;
        for(int i=0; i<nums.size(); ++i) {
            int val = 1;
            for(int j=0; j<nums.size(); ++j) {
                if(i!=j) {
                    val*=nums[j];
                }
            }
            result.push_back(val);
        }
        return result;
        }
};

Time & Space Complexity
Time complexity: 
O(n2)
Space complexity: 
O(1) since the output array is excluded from space analysis.

=========================================================================================
vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // Compute prefix product
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefix;
            prefix *= nums[i]; // Update prefix for next element
        }

        // Compute suffix product and update result in-place
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;
            suffix *= nums[i]; // Update suffix for next element
        }

        return result;
    }

