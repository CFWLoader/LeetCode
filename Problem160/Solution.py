__author__ = 'cfwloader'


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if headA is None or headB is None:
            return None

        ptr1 = headA; ptr2 = headB
        count1 = 1; count2 = 1

        steps = 0

        while ptr1.next is not None:
            ptr1 = ptr1.next
            count1 += 1

        while ptr2.next is not None:
            ptr2 = ptr2.next
            count2 += 1

        if ptr1 != ptr2:
            return None

        if count1 >= count2:
            ptr1 = headA; ptr2 = headB
            steps = count1 - count2
        elif count2 > count1:
            ptr1 = headB; ptr2 = headA
            steps = count2 - count1

        while steps > 0:
            ptr1 = ptr1.next
            steps -= 1

        while ptr1 is not None and ptr2 is not None and ptr1 != ptr2:
            ptr1 = ptr1.next; ptr2 = ptr2.next

        return ptr1