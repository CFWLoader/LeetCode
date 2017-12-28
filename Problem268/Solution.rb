# @param {Integer[]} nums
# @return {Integer}
def missing_number(nums)

  if nums.nil? or nums.size < 1
    return nil
  end

  result = 0

  nums.each_with_index { |val, idx|
    result += idx - val
  }

  result + nums.size

end

puts missing_number [0, 1, 3]

puts missing_number [0, 4, 5, 7, 1, 2, 3]