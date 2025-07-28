class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0, cnt=0, ans=0;
        int n=nums.size();
        unordered_map<int, int>mp;
        for(int it=1; it < (1<<n); it++){
            int val=it, indx=0; cnt=0;
            while(val>0){
                if(val%2==1) cnt |= nums[indx];
                val/=2; indx++;
            }
            mx = max(cnt, mx); mp[cnt]++;
        }
        ans = mp[mx];

        return ans;
    }
};

// Time complexity : O((2^N)*N)
// Space complexity : O(N)
