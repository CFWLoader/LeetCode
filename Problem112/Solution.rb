# Definition for a binary tree node.
class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end

# @param {TreeNode} root
# @param {Integer} sum
# @return {Boolean}
def has_path_sum(root, sum)

  if root.nil?
    return false
  end

  value = sum - root.val

  if value == 0 and root.left.nil? and root.right.nil?
    return true
  end

  left_result = has_path_sum root.left, value

  if left_result
    return true
  end

  has_path_sum root.right, value

end


root = TreeNode.new 1

root.left = TreeNode.new 2

puts has_path_sum root, 1

