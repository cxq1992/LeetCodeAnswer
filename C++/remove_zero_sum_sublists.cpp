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
	ListNode* removeZeroSumSublists(ListNode* head)
	{
		f[1000][1000] = { 0 };
		ListNode* curr = head;
		int i = 0;
		while (curr)
		{
			f[i][i] = curr->val;
			++i;
			curr = curr->next;
		}
		

	}
};