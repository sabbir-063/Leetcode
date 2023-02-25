/*
Problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Author : Sabbir Musfique
Time Complexity : O(n)
Space Complexity : O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>mxProfit(n,0);
        int mx=0;
        for(int i=n-1; i>0; i--){
            mxProfit[i] = max(mx, prices[i]), mx = max(mx, prices[i]);
        }
           
        int ans=0;
        for(int i=0;i<n-1;i++){
           int temp = mxProfit[i+1]-prices[i];
           ans=max(ans, temp);
        }

        return ans;  
    }
};
