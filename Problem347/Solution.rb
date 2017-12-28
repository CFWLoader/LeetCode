# @param {Integer[]} nums
# @param {Integer} k
# @return {Integer[]}
def top_k_frequent(nums, k)

  if nums.nil? or nums.size < 2
    return nums
  end

  nums.sort!

  statistic = []

  key = nums[0]; st = 0

  nums.each {|val|

    if key != val

      statistic << [key, st]

      key = val; st = 1

    else

      st += 1

    end
  }

  statistic << [key, st]

  statistic.sort! {|cur, nex|
    nex[1] <=> cur[1]
  }

  result_set = []

  0.upto(k - 1){|idx|
    result_set << statistic[idx][0]
  }

  result_set

end

result = top_k_frequent [1, 1, 1, 2, 2, 3], 2

print result

puts