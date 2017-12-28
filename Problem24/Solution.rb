# Definition for singly-linked list.
class ListNode
  attr_accessor :val, :next

  def initialize(val)
    @val = val
    @next = nil
  end
end

# @param {ListNode} head
# @return {ListNode}
def swap_pairs(head)

  if head.nil? or head.next.nil?
    return head
  end

  second_node = head

  head = head.next

  third_node = head.next

  head.next = second_node

  second_node.next = (third_node.nil? or third_node.next.nil?) ? third_node : third_node.next

  until third_node.nil? do
    ptr = third_node

    second_node = ptr.next

    if second_node.nil?
      return head
    end

    third_node = second_node.next

    second_node.next = ptr

    ptr.next = (third_node.nil? or third_node.next.nil?) ? third_node : third_node.next

  end

  head
end

head = ListNode.new 1

head.next = ListNode.new 2

head.next.next = ListNode.new 3

head.next.next.next = ListNode.new 4

head = swap_pairs head

ptr = head

until ptr.nil?
  print "#{ptr.val}->"

  ptr = ptr.next
end