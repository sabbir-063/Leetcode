class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int x1=n,y1=m,x2=0,y2=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    x1 = min(x1, i);
                    x2 = max(x2, i);
                    y1 = min(y1, j);
                    y2 = max(y2, j);
                }
            }
        } 

        return (x2-x1+1)*(y2-y1+1);
    }
};

// Time Complexity O(N∗M)
// Space Complexity O(1)
