# Definition for a binary tree node.
class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end

# @param {TreeNode} root
# @return {Boolean}
def is_balanced(root)

  if root.nil?
    return true
  end

  l_height, l_balanced = subtree_height root.left

  r_height, r_balanced = subtree_height root.right

  unless l_balanced and r_balanced
    return false
  end

  unless -1 <= l_height - r_height and l_height - r_height <= 1
    return false
  end

  true

end

def subtree_height(node)

  if node.nil?
    return 0, true
  end

  leftHeight, leftBalanced = subtree_height node.left

  rightHeight, rightBalanced = subtree_height node.right

  unless leftBalanced and rightBalanced
    return 0, false
  end

  balancedValue = leftHeight - rightHeight

  balanced = if balancedValue < -1 or balancedValue > 1 then false else true end

  unless balanced
    return 0, false
  end

  maxHeight = if leftHeight > rightHeight then leftHeight else rightHeight end

  return maxHeight + 1, true

end


root = TreeNode.new(1)

puts is_balanced root