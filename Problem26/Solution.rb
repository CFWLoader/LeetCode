# @param {Integer[]} nums
# @return {Integer}
def remove_duplicates(nums)

  if nums.nil? or nums.size < 1
    return 0
  end

  count = 1

  currentValue = nums[0]

  nextIndex = 1

  nums.each_with_index { |value, index|
    if value != currentValue
      nums[nextIndex] = value

      count += 1

      nextIndex += 1

      currentValue = value
    end
  }

  count
end

nums = [1, 1, 2, 2, 2, 3]

puts remove_duplicates nums

print nums

puts

case2 = []

puts remove_duplicates case2

print case2