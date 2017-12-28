# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search_insert(nums, target)

  if nums.nil? or nums.size < 1
    return 0
  end

  left = 0; right = nums.size - 1

  mid = left + Integer((right - left) / 2)

  while left < right

    if nums[mid] == target
      return mid
    elsif nums[mid] < target
      left = mid + 1
    else
      right = mid - 1
    end

    mid = left + Integer((right - left) / 2)

  end

  if nums[left] < target
    left += 1
  end

  left

end

puts search_insert [1, 3], 0

puts search_insert [1,3,5,6], 5

puts search_insert [1,3,5,6], 2

puts search_insert [1,3,5,6], 7

puts search_insert [1,3,5,6], 0