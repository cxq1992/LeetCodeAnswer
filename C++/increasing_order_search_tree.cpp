/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* increasingBST(TreeNode* root) {
		if (!root)
		{
			return root;
		}
		if (!root->left)
		{
			root->right = increasingBST(root->right);
			return root;
		}
		if (root)
	}
};