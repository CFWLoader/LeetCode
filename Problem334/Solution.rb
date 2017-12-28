# @param {Integer[]} nums
# @return {Boolean}
def increasing_triplet(nums)
  if nums.length < 3
    return false
  end

  bound1 = nums.max

  bound2 = bound1 + 1

  bound1 = bound2

  nums.each { |element|

    # print element, '(', bound1, ',', bound2, ') '

    if element <= bound1
      bound1 = element
    elsif element <= bound2
      bound2 = element
    else
      return true
    end

  }

  # puts

  false
end


nums = [1, 2, 3]

puts increasing_triplet []

puts increasing_triplet [1, 5]

puts increasing_triplet nums

puts increasing_triplet [5, 4, 3, 2, 1]