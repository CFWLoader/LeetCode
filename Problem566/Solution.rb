# @param {Integer[][]} nums
# @param {Integer} r
# @param {Integer} c
# @return {Integer[][]}
def matrix_reshape(nums, r, c)

  if nums.size == 0 or nums.size * nums[0].size != r * c

    return nums

  end

  ret_mat = []

  new_row = []

  c_idx = 0

  nums.each {|row|

    row.each {|ele|

      if c_idx < c

        new_row << ele

        c_idx += 1

      else

        ret_mat << new_row

        new_row = [ele]

        c_idx = 1

      end

    }

  }

  ret_mat << new_row

  ret_mat

end


if $0 == __FILE__

  nums = [[1, 2], [3, 4]]

  p matrix_reshape nums, 1, 4

  nums = [[1, 2, 3, 4], [5, 6, 7, 8]]

  p matrix_reshape nums, 4, 2

end