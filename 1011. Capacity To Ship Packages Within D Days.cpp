/*
Problem : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

Author : Sabbir Musfique
Time Complexity : O(n log(n))

*/

class Solution {
public:
    bool possible(vector<int>&wt, int cap, int days){
        int dd=1, cnt=0;
        
        for(auto i : wt){
            cnt += i;
            if(cnt > cap) dd++, cnt=i;
        }
        
        return dd <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int mx=0, cnt=0;
        for(auto i : weights) mx=max(mx, i), cnt += i;
        int l=mx, r=cnt;
        
        while(l < r){
            int mid = (l+r) >> 1;
            if(possible(weights, mid, days)) r = mid;
            else l=mid+1;
        }
        
        return l; 
    }
};
