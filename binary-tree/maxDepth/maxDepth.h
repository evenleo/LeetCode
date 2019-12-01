/*
* 题目：给定一个二叉树，找出其最大深度。
*      二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*
* 说明: 叶子节点是指没有子节点的节点。
*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth > rightDepth ? 1 + leftDepth : 1 + rightDepth;
    }
};