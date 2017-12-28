__author__ = 'cfwloader'


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head is None:
            return head

        if n == 1:
            node = head.next

            if node is None:
                return node

            preNode = head

            while node.next is not None:
                preNode = node

                node = node.next

            preNode.next = None

            return head

        dict = {}

        index = 1

        iterator = head

        while iterator is not None:

            dict[index] = iterator

            iterator = iterator.next

            index += 1

        target = dict[index - n]

        if target == head:
            return target.next
        else:
            dict[index - n - 1].next = target.next

        return head


if __name__ == '__main__':

    '''
    [1,2,3]
    2
    '''