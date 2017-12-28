# Definition for a binary tree node.
class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end

# @param {TreeNode} root
# @return {Integer[][]}
def level_order(root)

  if root.nil?
    return []
  end

  if root.left.nil? and root.right.nil?
    return [[root.val]]
  end

  treeQueue = Array.new

  treeQueue << root

  treeQueue << '#'

  index = 0

  matrix = []

  vector = Array.new

  while index < treeQueue.size

    # print "#{treeQueue}\n"

    if treeQueue[index].class == '#'.class

      if (index + 1 < treeQueue.size)
        treeQueue << '#'
      end

      matrix << vector

      vector = Array.new

    else

      vector << treeQueue[index].val

      unless treeQueue[index].left.nil?
        treeQueue << treeQueue[index].left
      end

      unless treeQueue[index].right.nil?
        treeQueue << treeQueue[index].right
      end

    end

    index += 1
  end

  matrix
end

root = TreeNode.new(1)

root.left = TreeNode.new(2)

root.right = TreeNode.new(3)

root.left.left = TreeNode.new(4)

# root.left.left.right = TreeNode.new(5)

root.right.left = TreeNode.new(4)

# root.right.right = TreeNode.new(5)

print level_order root