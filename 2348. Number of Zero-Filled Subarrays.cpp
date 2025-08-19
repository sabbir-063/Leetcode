class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0, cnt=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                cnt++; ans += cnt;
            }
            else{
                cnt=0;
            }
        }

        return ans;
    }
};

//Time Complexity O(N)
//Space Complexity O(1)
