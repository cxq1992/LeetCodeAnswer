#include <iostream>
struct ListNode
{
  int val;
  ListNode* next;
};

ListNode* ReverseList(ListNode *head)
{ 
	if (!head || !head->next)
	{
		return head;
	}  
	ListNode* curr = head->next;
	head->next = nullptr;
    while (curr)
	{
		ListNode * tmp = curr->next;
		curr->next = head;
		head = curr;
		curr = tmp;
	}
	return head;
}

void Print(ListNode * head)
{
	while (head)
	{
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

int main()
{
	ListNode * head = new ListNode();
	ListNode * curr = head;
	curr->next = nullptr;
	for (size_t i = 0; i < 10; ++i)
	{
		curr->next = new ListNode();
		curr = curr->next;
		curr->val = i;
		curr->next = nullptr;
	}
	Print(head->next);
	Print(ReverseList(head->next));
	while (head)
	{
		curr = head->next;
		delete head;
		head = curr;
	}
}