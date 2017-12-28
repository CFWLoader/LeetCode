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
def min_depth(root)

  if root.nil?
    return 0
  end

  if root.left.nil? and root.right.nil?
    return 1
  end

  l_depth = min_depth root.left

  r_depth = min_depth root.right

  if root.right.nil?
    min_depth_ = l_depth
  elsif root.left.nil?
    min_depth_ = r_depth
  else
    min_depth_ = l_depth < r_depth ? l_depth : r_depth
  end

  min_depth_ + 1

end

root = TreeNode.new(1)

root.left = TreeNode.new(2)

puts min_depth root