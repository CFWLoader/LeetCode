/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* deletePtr = NULL;
        
        while(head != NULL && head->val == val)
        {
            deletePtr = head;
            
            head = head->next;
            
            delete deletePtr;
            
            deletePtr = NULL;
        }
        
        ListNode* ptr = head;
        
        while(ptr != NULL)
        {
            if(ptr->next != NULL && ptr->next->val == val)
            {
                deletePtr = ptr->next;
                
                ptr->next = ptr->next->next;
                
                delete deletePtr;
            }
            else
            {
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};