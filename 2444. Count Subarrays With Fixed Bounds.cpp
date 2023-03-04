/*
Problem : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int Min=-1, Max=-1, bound=-1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= minK and nums[i] <= maxK){
                Min = (nums[i] == minK)? i : Min;
                Max = (nums[i] == maxK)? i : Max;
                ans += max(0, min(Min, Max)-bound);
            }else{
                bound=i, Min=-1, Max=-1;
            }
        }
        
        return ans;
    }
};
