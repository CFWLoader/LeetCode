# @param {Integer[]} nums
# @return {String[]}
def summary_ranges(nums)

  if nums.nil? or nums.size < 1
    return []
  end

  if nums.size == 1
    return [nums[0].to_s]
  end

  range_statistic = Array.new

  bound = nums.size

  last_val = nums[0] - 2

  range_str = nil

  nums.each_with_index { |num, index|

    if num != last_val + 1

      unless range_str.nil?

        range_str = range_str + last_val.to_s

        range_statistic << range_str;

      end

      if index + 1 < bound and nums[index + 1] == num + 1
        range_str = num.to_s + "->";

        last_val = num
      else
        range_statistic << num.to_s

        range_str = nil
      end


    else

      if index + 1 == bound
        unless range_str.nil?

          range_str = range_str + (last_val + 1).to_s

          range_statistic << range_str;

        end
      end

      last_val += 1

    end

  }

  range_statistic
end

print summary_ranges [0,1,2,4,5,7,9,10,12,14,15,16,27,28]

puts

# print summary_ranges [1, 3]
#
# puts
#
# print summary_ranges [0]
#
# puts
#
# ranges = summary_ranges [0, 1, 2, 4, 5, 7]
#
# print ranges
#
# puts
#
# ranges = summary_ranges [0, 1]
#
# print ranges
#
# puts
#
# ranges = summary_ranges [0, 1, 2, 4, 5, 7, 8]
#
# print ranges
#
# puts