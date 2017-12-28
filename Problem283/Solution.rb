# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)

  if nums.nil? or nums.size < 1
    return
  end

  zero_count = 0

  nums.each{|n| if n == 0 then zero_count += 1 end}

  bound = nums.size

  slot_index = 0

  target_index = slot_index

  while target_index < bound

    while target_index < bound and nums[target_index] == 0 do target_index += 1 end

    if target_index < bound

      nums[slot_index] = nums[target_index]

      slot_index += 1

    end

    target_index += 1
  end

  slot_index = bound - 1

  while zero_count > 0 do nums[slot_index] = 0; slot_index -= 1; zero_count -= 1; end

end

nums = [0, 1, 0, 3, 12]

move_zeroes nums

print nums

puts