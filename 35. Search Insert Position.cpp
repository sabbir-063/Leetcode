/*
Problem : https://leetcode.com/problems/search-insert-position/

Author : Sabbir Musfique
Time Complexity : O(log(n)) // binary search
Space Complexity : O(1)

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int indx=lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        return indx;
    }
};
