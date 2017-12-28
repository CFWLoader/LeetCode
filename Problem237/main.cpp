#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {

    int val;

    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    void deleteNode(ListNode* node) {

        if(node == nullptr)return;

        node->val = node->next->val;

        ListNode* temp = node->next;

        node->next = node->next->next;

        delete temp;

        temp = nullptr;
    }
};

int main()
{
    int numberOfNodes;

    cin >> numberOfNodes;

    ListNode* head = new ListNode(0);

    ListNode* ptr = head;

    int i = 0;

    do
    {
        cin >> ptr->val;

        ptr->next = new ListNode(0);

        ptr = ptr->next;

        ++i;

    }while(i < numberOfNodes);

    for(ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->val << " ";
    }

    cout << endl;

    Solution solution;

    solution.deleteNode(head->next->next);

    for(ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << ptr->val << " ";
    }

    cout << endl;

    return 0;
}