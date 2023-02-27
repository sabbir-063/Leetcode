/*
Problem : https://leetcode.com/problems/jump-game-ii/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int en=0,st=0,ans=0;

        for(int i=0;i<n-1;i++){
            st=max(st, i+nums[i]);
            if(i == en){
                ans++; en=st;
            }
        }

        return ans;
    }
};
