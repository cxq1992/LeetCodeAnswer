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
		return dfs(root).first;
	}
private:
	typedef std::pair<TreeNode*, TreeNode*> NodePair;
	NodePair dfs(TreeNode* root)
	{
		if (!root)
		{
			return std::make_pair(nullptr, nullptr);
		}
		NodePair left = dfs(root->left);
		NodePair right = dfs(root->right);
		root->left = nullptr;
		root->right = nullptr;
		if (left.first == nullptr && right.first == nullptr)
		{
			return std::make_pair(root, root);
		}
		if (left.first == nullptr && right.first != nullptr)
		{
			root->right = right.first;
			return std::make_pair(root, right.second);
		}
		if (left.first != nullptr && right.first == nullptr)
		{
			left.second->right = root;
			return std::make_pair(left.first, root);
		}
		left.second->right = root;
		root->right = right.first;
		return std::make_pair(left.first, right.second);
	}
};