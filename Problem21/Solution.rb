# Definition for singly-linked list.
class ListNode

  attr_accessor :val, :next

  def initialize(val)
    @val = val
    @next = nil
  end

end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def merge_two_lists(l1, l2)

  if l1.nil?
    return l2
  end

  if l2.nil?
    return l1
  end

  head = l1.val < l2.val ? l1 : l2

  ptr = head

  ptr1 = head == l1 ? l1.next : l1

  ptr2 = head == l2 ? l2.next : l2

  until ptr1.nil? or ptr2.nil?

    if ptr1.val <= ptr2.val

      ptr.next = ptr1

      ptr1 = ptr1.next

    else

      ptr.next = ptr2

      ptr2 = ptr2.next

    end

    ptr = ptr.next

  end

  if ptr1.nil?
    ptr.next = ptr2
  else
    ptr.next = ptr1
  end

  head

end