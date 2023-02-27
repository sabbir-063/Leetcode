/*
Problem : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Author : Sabbir Musfique
Time Complexity : O(1)
Space Complexity : O(1)
*/

class Solution {
public:
    int countOdds(int low, int high) {
        int x=high-low;
        int xx=x/2;
        if(low%2==0 and high%2==0) return xx;
        return xx+1;
    }
};
