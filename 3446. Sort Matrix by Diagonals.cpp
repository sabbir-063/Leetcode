class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>ans = grid;
        int i=0, j=n-1; 

        while(true){
            vector<int>tmp;
            int ii=i, jj=j;

            while(ii<n and jj<n){
                tmp.push_back(grid[ii][jj]); ii++; jj++;
            }

            if(j>0) sort(tmp.begin(), tmp.end());
            else sort(tmp.begin(), tmp.end(), greater<int>());

            int indx=0; ii=i, jj=j;
            while(ii<n and jj<n) ans[ii++][jj++] = tmp[indx++];

            if(j == 0 or i > 0) i++, j=0;
            else i=0, j--; 
            if(i == n) break;
        }


        return ans;
    }
};

// Time Complexity O(N^2*Logn)
// Space Complexity O(N^2)
