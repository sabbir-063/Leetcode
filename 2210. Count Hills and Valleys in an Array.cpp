class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0;
        int left=0;
        int n=nums.size();

        for(int i=1; i<n-1; i++){
            if(nums[i]>nums[left] and nums[i]>nums[i+1]) ans++, left=i;
            if(nums[i]<nums[left] and nums[i]<nums[i+1]) ans++, left=i;
            // cout<<ans<<" "<<i<<" "<<left<<endl;
        }

        return ans;
    }
};

// Time Complexity : O(N) 
// Space Complexity : O(1) 
