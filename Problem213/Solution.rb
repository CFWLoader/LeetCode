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

  head_presented = max_array[0] == nums[0] ? TRUE : FALSE

  index = 2

  while index < array_size - 1

    max_array[index] = max_array[index - 2] + nums[index] > max_array[index - 1] ? max_array[index - 2] + nums[index] : max_array[index - 1]

    index += 1
  end

  puts max_array[array_size - 2]

  max_array[array_size - 1] = head_presented ? max_array[array_size - 2] : max_array[array_size - 2] + nums[array_size - 1]

  max_val = max_array[array_size - 1]

  index = array_size - 1

  max_array[index] = nums[index]

  max_array[index - 1] = nums[index] > nums[index - 1] ? nums[index] : nums[index - 1]

  head_presented = max_array[index] == nums[index] ? TRUE : FALSE

  index = array_size - 2

  while index > 0

    max_array[index - 1] = max_array[index + 1] + nums[index - 1] > max_array[index] ? max_array[index + 1] + nums[index - 1] : max_array[index]

    index -= 1

  end

  max_array[0] = head_presented ? max_array[1] : max_array[2] + nums[0]

  max_array[0] > max_val ? max_array[0] : max_val

end

puts rob [1, 3, 5, 7, 9]