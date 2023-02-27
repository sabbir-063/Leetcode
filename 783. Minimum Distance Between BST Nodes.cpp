/*
Problem : https://leetcode.com/problems/minimum-distance-between-bst-nodes/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(N) // recursive stack space
*/

class Solution {
public:
    int mn = 1e6, i=0;
    int arr[101]={0};
    int minDiffInBST(TreeNode* root) {
        if(root){
            minDiffInBST(root->left);
            arr[i++] = root->val;
            minDiffInBST(root->right);
        }

        return mn;
    }
};
