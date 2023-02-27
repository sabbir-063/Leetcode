/*
Problem : https://leetcode.com/problems/single-element-in-a-sorted-array/

Author : Sabbir Musfique
Time Complexity : O(log(n)) // binary search
Space Complexity : O(1)

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mid=0;
        while(l < r){
            mid = (l+r) >> 1;
            if(mid&1){
                if(nums[mid] != nums[mid+1]) l=mid+1;
                else r=mid;
            }
            else{
                if(nums[mid] == nums[mid+1]) l=mid+1;
                else r=mid;
            }
        }
        return nums[l];
    }
};
