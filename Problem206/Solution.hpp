// Definition for singly-linked list.
struct ListNode {

	int val;

	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
    	if(head == NULL || head->next == NULL)
    	{
    		return head;
    	}

    	ListNode* ptr, *next;

    	ptr = head->next;

    	next = ptr->next;

    	head->next = NULL;

    	while(next != NULL)
    	{
    		ptr->next = head;

    		head = ptr;

    		ptr = next;

    		next = ptr->next;
    	}

    	ptr->next = head;

    	return ptr;
    }
};