class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    dp[i+1][j+1] = 1 + min({dp[i+1][j], dp[i][j], dp[i][j+1]});
                    ans += dp[i+1][j+1];
                }
            }
        }

        return ans;
    }
};

//Time Complexity O(N∗M)
//Space Complexity O(N∗M)
