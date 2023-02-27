/*
Problem : https://leetcode.com/problems/shuffle-the-array/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int j=0;
        for(int i=0;i<n;i++) ans[j++] = nums[i], ans[j++] = nums[n+i];
        return ans;
    }
};
