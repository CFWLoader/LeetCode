# @param {Integer[]} nums
# @return {Integer[][]}
def three_sum(nums)

  nums.sort!

  bound = nums.size

  result_set = Array.new

  index = 0

  until index >= bound

    left = index + 1; right = bound - 1

    until left >= right

      if nums[index] + nums[left] + nums[right] == 0

        result_set << [nums[index], nums[left], nums[right]]

        while left < right and nums[left] == nums[left + 1] do
          left += 1
        end
        while left < right and nums[right] == nums[right - 1] do
          right -= 1
        end

        left += 1
        right -= 1

      elsif nums[index] + nums[left] + nums[right] < 0

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

  result_set

end

# result = three_sum [1, 3, -1, 7, 2, 6, 0, 5]
result = three_sum [-1, 0, 1, 2, -1, -4]

print result