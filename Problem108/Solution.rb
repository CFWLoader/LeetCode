# Definition for a binary tree node.
class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

# @param {Integer[]} nums
# @return {TreeNode}
def sorted_array_to_bst(nums)

  if nums.nil? or nums.size < 1
    return nil
  end

  form_node nums, 0, nums.size - 1
end

def form_node(nums, left, right)

  if left > right
    return nil
  end

  if left == right
    return TreeNode.new nums[left]
  end

  mid = left + Integer((right - left) / 2)

  root = TreeNode.new nums[mid]

  root.left = form_node nums, left, mid - 1

  root.right = form_node nums, mid + 1, right

  root

end

root = sorted_array_to_bst [1, 3]

puts root.val

puts root.right.val