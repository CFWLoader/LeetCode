# Definition for a binary tree node.
class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

# @param {TreeNode} root
# @return {Integer}
def rob(root)

  with_root, without_root = traverse root

  max_val with_root, without_root

end

def max_val(a, b)
  a > b ? a : b
end

def traverse(root)

  l_max_with_root = 0; l_max_without_root = 0
  r_max_with_root = 0; r_max_without_root = 0
  max_with_root = 0; max_without_root = 0

  unless root.nil?

    l_max_with_root, l_max_without_root = traverse root.left

    r_max_with_root, r_max_without_root = traverse root.right

    max_with_root = l_max_without_root + r_max_without_root + root.val

    max_without_root = max_val(l_max_with_root, l_max_without_root) + max_val(r_max_with_root, r_max_without_root)

  end

  return max_with_root, max_without_root

end

root1 = TreeNode.new 3

root1.left = TreeNode.new 2

root1.left.right = TreeNode.new 3

root1.right = TreeNode.new 3

root1.right.left = TreeNode.new 1

puts rob root1

root2 = TreeNode.new 3

root2.left = TreeNode.new 4

root2.right = TreeNode.new 5

root2.left.left = TreeNode.new 1

root2.left.right = TreeNode.new 3

root2.right.right = TreeNode.new 1

puts rob root2
