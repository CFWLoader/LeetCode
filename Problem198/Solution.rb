# @param {Integer[]} nums
# @return {Integer}
def rob(nums)

  if nums.nil? or nums.size < 1
    return 0
  end

  if nums.size == 1
    return nums[0]
  end

  if nums.size == 2
    return nums[0] > nums[1] ? nums[0] : nums[1]
  end

  array_size = nums.size

  max_array = Array.new array_size

  max_array[0] = nums[0]

  max_array[1] = nums[0] > nums[1] ? nums[0] : nums[1]

  index = 2

  until index >= array_size

    max_array[index] = max_array[index - 2] + nums[index] > max_array[index - 1] ? max_array[index - 2] + nums[index] : max_array[index - 1]

    index += 1
  end

  # print "#{max_array}\n"

  max_array[array_size - 1]

end

puts rob [3, 1, 1, 3, 1, 2]

puts rob [2, 3, 2]