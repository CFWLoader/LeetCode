# @param {Integer} n
# @return {Integer}
def num_trees(n)
  calculate_subtrees 1, n
end

def calculate_subtrees(left, right)

  if left >= right
    return 1
  end

  total_count = 0

  left.upto(right){ |root|

    left_count = calculate_subtrees left, root - 1

    right_count = calculate_subtrees root + 1, right

    total_count += left_count * right_count

  }

  total_count
end

1.upto(10) { |num|
  print "#{num}: #{num_trees num}\n"
}