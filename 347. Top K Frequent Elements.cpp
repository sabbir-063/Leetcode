/*
Problem : https://leetcode.com/problems/top-k-frequent-elements/

Author : Sabbir Musfique
Time Complexity : O(N log(N))
Space Complexity : O(N)

*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        for(auto i:nums) mp[i]++;
        vector<pair<int,int>>v;
        auto it=mp.begin();
        int kk=mp.size();
        while(kk--){
            v.push_back({it->second, it->first});
            it++;
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());

        for(int i=0;i<k;i++) ans.push_back(v[i].second); 

        return ans;
    }
};
