class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int cnt = n*m;
        vector<int>ans;
        int i=0, j=0, elem=0;
        bool flag=true;

        while(elem < cnt){
            ans.push_back(mat[i][j]); elem++;
            if(flag){
                if(j == m-1) flag=false, i++;
                else if(i == 0) flag=false, j++;
                else i--, j++;
            }
            else{
                if(i == n-1) flag=true, j++;
                else if(j == 0) flag=true, i++;
                else i++, j--;    
            }
        }

        return ans;
    }
};

// Time complexity : O(N*M)
// Sapce complexity : O(1)
