/*
Problem : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Author : Sabbir Musfique
Time Complexity : O(nlog(n)) // level order traversal
Space Complexity : O(n)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root == nullptr) return ans;
        int i=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            while(n--){
                TreeNode* front = q.front();
                v.push_back(front->val);
                q.pop();
                if(front->left != nullptr) q.push(front->left);
                if(front->right != nullptr) q.push(front->right);
            }
            if(i++ % 2) reverse(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};
