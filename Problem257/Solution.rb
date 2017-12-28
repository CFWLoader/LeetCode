# Definition for a binary tree node.
class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left, @right = nil, nil
  end
end

# @param {TreeNode} root
# @return {String[]}
def binary_tree_paths(root)

  if root.nil?
    return []
  end

  if root.left.nil? and root.right.nil?
    return [root.val.to_s]
  end

  from_left_tree = binary_tree_paths root.left

  from_right_tree = binary_tree_paths root.right

  this_tree = Array.new

  from_left_tree.each do |str|

    this_tree << root.val.to_s + '->' + str

  end

  from_right_tree.each do |str|

    this_tree << root.val.to_s + '->' + str

  end

  this_tree
end