class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans;
        for(int i=1; i<=n; i++){
            vector<int>v(i, 1);
            if(i < 3) ans.push_back(v);
            else{
                for(int j=2; j<i; j++){
                    v[j-1] = ans[i-2][j-2] + ans[i-2][j-1];
                }
                ans.push_back(v);
            }
        }

        return ans;
    }
};
