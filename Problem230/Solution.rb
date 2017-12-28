# Definition for a binary tree node.
class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

# @param {TreeNode} root
# @param {Integer} k
# @return {Integer}
def kth_smallest(root, k)

  if root.nil?
    return -1
  end

  ptr = root

  node_stack = Array.new

  k_count = 0

  until k_count == k

    if ptr.nil?
      ptr = node_stack.pop

      k_count += 1

      if k_count == k
        break
      end

      ptr = ptr.right

    else
      node_stack.push ptr
      ptr = ptr.left
    end

  end

  ptr.val
end

tree = TreeNode.new 4

tree.left = TreeNode.new 2

tree.left.left = TreeNode.new 1

tree.left.right = TreeNode.new 3

tree.right = TreeNode.new 6

tree.right.left = TreeNode.new 5

tree.right.right = TreeNode.new 7

# tree = TreeNode.new 1

target = kth_smallest tree, 6

puts target