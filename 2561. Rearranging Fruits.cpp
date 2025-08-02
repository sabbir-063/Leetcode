class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int>mp;
        int mn = INT_MAX;
        for(auto it : basket1){
            mp[it]++; mn=min(mn, it);
        }
        for(auto it : basket2){
            mp[it]--; mn=min(mn, it);
        }

        vector<int>m;
        for(auto it : mp){
            if(it.second % 2 == 1) return -1;
            for(int i=0; i<abs(it.second)/2; i++) m.push_back(it.first);
        }
        
        sort(m.begin(), m.end());
        long long ans=0; int n=m.size();
        for(int i=0; i<n/2; i++){
            ans += min(m[i], 2*mn);
        }

        return ans;
    }
};

//Time complexity : O(NlogN)
//Space complexity : O(N)
