# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def three_sum_closest(nums, target)

  if nums.nil? or nums.size < 3
    return 0
  end

  nums.sort!

  bound = nums.size

  current_target = nums[0] + nums[1] + nums[2]

  print nums

  puts

  index = 0

  until index >= bound

    left = index + 1; right = bound - 1

    until left >= right

      assumed_target = nums[index] + nums[left] + nums[right]

      # print "1: #{nums[index]}, 2: #{nums[left]}, 3: #{nums[right]}  "

      # print "Assumed: #{assumed_target} Abs: #{(assumed_target - target).abs}, Current: #{current_target} abs: #{(current_target - target).abs}\n"

      if (assumed_target - target).abs < (current_target - target).abs
        current_target = assumed_target
      end

      while left < right and nums[left] == nums[left + 1] do
        left += 1
      end
      while left < right and nums[right] == nums[right - 1] do
        right -= 1
      end

      if  assumed_target < target
        left += 1
      else
        right -= 1
      end

    end

    index += 1

    while index > 0 and nums[index] == nums[index - 1]
      index += 1
    end

  end

  current_target

end

# result = three_sum [1, 3, -1, 7, 2, 6, 0, 5]
# result = three_sum_closest [-1, 2, 1, -4], 1
# result = three_sum_closest [0, 2, 1, -3], 1
result = three_sum_closest [1,2,4,8,16,32,64,128], 82         # Expected 82

print result