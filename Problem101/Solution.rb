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
def is_symmetric(root)

  if root.nil?
    return true
  end

  if root.left.nil? and root.right.nil?
    return true
  end

  leftVector = []
  rightVector = []

  collect_left root.left, leftVector

  collect_right root.right, rightVector

  if leftVector.size != rightVector.size
    return false
  end

  index = 0

  bound = leftVector.size

  while index < bound and leftVector[index] == rightVector[index]
    index += 1
  end

  if index != bound
    false
  else
    true
  end

end

def collect_left(node, vector)

  if node.nil?

    vector << '#'

    return
  end

  vector << node.val

  collect_left node.left, vector

  collect_left node.right, vector

end

def collect_right(node, vector)

  if node.nil?

    vector << '#'

    return
  end

  vector << node.val

  collect_right node.right, vector

  collect_right node.left, vector
end