# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}
def remove_element(nums, val)

  if nums.nil? or nums.size < 1
    return 0
  end

  bound = nums.size

  tail = bound - 1

  index = 0

  while index < tail

    if nums[index] == val

      while index < tail and nums[tail] == val
        tail -= 1
      end

      nums[index], nums[tail] = nums[tail], nums[index]
    end

    index += 1
  end

  if nums[tail] == val
    tail -= 1
  end

  tail + 1
end

arr1 = [1,2,3]

puts remove_element arr1, 2

print arr1

puts