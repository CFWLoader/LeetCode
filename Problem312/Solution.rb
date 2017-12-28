# @param {Integer[]} nums
# @return {Integer}
def max_coins(nums)

  if nums.nil? or nums.size < 1
    return 0
  end

  nums.unshift(1); nums << 1

  nums_size = nums.size

  dp_matrix = Array.new nums_size

  0.upto(nums_size - 1) {|idx| dp_matrix[idx] = Array.new nums_size, 0}

  2.upto(nums_size - 1){|k|

    0.upto(nums_size - k - 1) {|left|

      right = left + k

      (left + 1).upto(right - 1){|i|

        dp_left = dp_matrix[left][right]; dp_right = nums[left] * nums[i] * nums[right] + dp_matrix[left][i] + dp_matrix[i][right]

        dp_matrix[left][right] = dp_left > dp_right ? dp_left : dp_right

      }
    }
  }

  dp_matrix[0][nums_size - 1]

end

puts max_coins [3, 1, 5, 8]