/*
Problem : https://leetcode.com/problems/construct-quad-tree/

Author : Sabbir Musfique
Time Complexity : O(N^2log(N)) i.e : N^2 cells and recursive call log(N)
Space Complexity : O(N*N)
*/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* create(vector<vector<int>>& grid, int rowStrt, int rowEnd, int colStrt, int colEnd){
        if((rowStrt > rowEnd) or (colStrt > colEnd))
            return NULL;

        bool isLeaf = true;
        int val=grid[rowStrt][colStrt];
        for(int i=rowStrt; i <= rowEnd; i++){
            for(int j=colStrt; j <= colEnd; j++){
                if(grid[i][j] != val){
                    isLeaf=false; break;
                }
            }
            if(isLeaf == false) break;
        }
        if(isLeaf)
            return new Node(val, true);
        
        int rowMid = (rowStrt+rowEnd)/2;
        int colMid = (colStrt+colEnd)/2;
        Node* topLeft = create(grid, rowStrt, rowMid, colStrt, colMid);
        Node* topRight = create(grid, rowStrt, rowMid, colMid+1, colEnd);
        Node* botLeft = create(grid, rowMid+1, rowEnd, colStrt, colMid);
        Node* botRight = create(grid, rowMid+1, rowEnd, colMid+1, colEnd);
        
        return new Node(false, false, topLeft, topRight, botLeft, botRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return create(grid, 0, n-1, 0, n-1);
    }
};


/// Alternative solution

Node* zero = new Node(false, true);
Node* one = new Node(true, true);

class Solution {
public:
    Node* construct(vector<vector<int>>& v) {
        return construct(v, 0, 0, v.size());    
    }
private:
    Node* construct(const vector<vector<int>>& v, int x, int y, int sz) {
        if (sz == 1) {
            return v[x][y] == 1 ? one : zero;
        }
        int hsz = sz / 2;
        Node *tl = construct(v, x, y, hsz);
        Node *tr = construct(v, x, y+hsz, hsz);
        Node *bl = construct(v, x+hsz, y, hsz);
        Node *br = construct(v, x+hsz, y+hsz, hsz);
        if (tl == tr && bl == br && tl == bl) {
            return tl;
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};
