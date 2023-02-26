/*
Problem : https://leetcode.com/problems/edit-distance/

Author : Sabbir Musfique
Time Complexity : O(m*n)
Space Complexity : O(m*n)
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        int dp[m+1][n+1];
        for(int i=0; i<=m; i++) dp[i][0]=i;
        for(int i=0; i<=n; i++) dp[0][i]=i;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insrt = 1+dp[i][j-1];
                    int delet = 1+dp[i-1][j];
                    int replce = 1+dp[i-1][j-1];

                    dp[i][j] = min({insrt, delet, replce});
                }
            }
        }

        return dp[m][n];
    }
};
