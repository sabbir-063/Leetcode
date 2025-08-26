class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int ans=0;
        double angle = 0.0;
        for(auto it : dim){
            double val = 1.0 * sqrt(it[0]*it[0] + it[1]*it[1]);
            if(val >= angle){
                angle = val;
            }
        }

        for(auto it : dim){
            double val = 1.0 * sqrt(it[0]*it[0] + it[1]*it[1]);
            if(val == angle){
                ans = max(ans, it[0]*it[1]);
            }
        }

        return ans;
    }
};

// Time Complexity O(N)
// Space Complexity O(1)
