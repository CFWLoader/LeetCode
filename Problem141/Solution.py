__author__ = 'cfwloader'

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head is None:
            return False

        slowPtr = head

        fastPtr = head

        while fastPtr is not None and fastPtr.next is not None:
            if fastPtr.next == slowPtr:
                return True

            slowPtr = slowPtr.next

            fastPtr = fastPtr.next.next

        return False