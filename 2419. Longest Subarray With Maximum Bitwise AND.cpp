class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=1, cnt=1;
        int n=nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]) cnt++;
            else{
                if(nums[i] == mx) ans = max(ans, cnt);
                cnt=1;
            }
        }
        if(cnt > 1 and nums[n-1] == mx) ans = max(ans, cnt);

        return ans;
    }
};

// Time complexity : O(N)
// Space complexity : O(1)
