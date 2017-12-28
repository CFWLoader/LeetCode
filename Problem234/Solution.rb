# Definition for singly-linked list.
class ListNode

    attr_accessor :val, :next

    def initialize(val)
        @val = val
        @next = nil
    end
end

# @param {ListNode} head
# @return {Boolean}
def is_palindrome(head)

  if head.nil? or head.next.nil?
    return true
  end

  value_array = Array.new

  ptr = head

  until ptr.nil?

    value_array << ptr.val

    ptr = ptr.next

  end

  left = 0; right = value_array.size - 1

  while left < right

    if value_array[left] != value_array[right]
      return false
    end

    left += 1; right -= 1
  end

  true

end


head = ListNode.new 1

head.next = ListNode.new 2

head.next.next = ListNode.new 1

puts is_palindrome head