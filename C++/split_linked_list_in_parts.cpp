/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k)
	{
		vector<ListNode *> res;
		int length = 0;
		ListNode * curr = root;
		while (curr)
		{
			++length;
			curr = curr->next;
		}
		int part = length / k;
		int rest = length % k;
		curr = root;
		while (k--)
		{
			int tmp_part = part;
			if (rest > 0)
			{
				++tmp_part;
				--rest;
			}
			res.push_back(curr);
			while (--tmp_part && curr)
			{
				if (tmp_part <= 0)
				{
					break;
				}
				curr = curr->next;
			}
			if (curr)
			{
				ListNode * tmp_next = curr->next;
				curr->next = nullptr;
				curr = tmp_next;
			}
		}
		return res;
	}
};