/*
Problem : https://leetcode.com/problems/find-duplicate-subtrees/

Author : Sabbir Musfique
Time Complexity : O(N)
Space Complexity : O(N)
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
    unordered_map<string, int> mp;
    vector<TreeNode*>ans;
    string findAns(TreeNode* node){
        if(node == NULL) return ".";

        string left = findAns(node->left);
        string right = findAns(node->right);
        string temp = left + "," + right + ", " + to_string(node->val);

        mp[temp]++;
        if(mp[temp] == 2) ans.push_back(node);
        return temp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        findAns(root);
        return ans;
    }
};
