# @param {Integer[]} nums
# @return {Integer[]}
def product_except_self(nums)

  if nums.nil? or nums.size < 1
    return []
  end

  result_set = Array.new nums.size, 1

  product = 1

  nums.each_with_index { |val, idx|

    result_set[idx] = product

    product *= val

  }

  idx = nums.size - 1

  product = 1

  until idx < 0

    result_set[idx] *= product

    product *= nums[idx]

    idx -= 1

  end

  result_set
end

result = product_except_self [1, 2, 3, 4]

print result

puts