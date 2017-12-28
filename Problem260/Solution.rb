# @param {Integer[]} nums
# @return {Integer[]}
def single_number(nums)

  if nums.nil? or nums.size < 1
    return []
  end

  xor_result = 0

  nums.each { |num|
    xor_result ^= num                       # Step 1.
  }

  mask = xor_result & ~(xor_result - 1)     # Step 2.

  target1 = 0; target2 = 0

  nums.each { |num|

    if num & mask > 0                       # Step 3 and 4.
      target1 ^= num
    else
      target2 ^= num
    end

  }

  [target1, target2]

end


result = single_number [1, 2, 1, 3, 2, 5]

print result

puts

result = single_number [2, 1, 2, 3, 4, 1]

print result

puts
