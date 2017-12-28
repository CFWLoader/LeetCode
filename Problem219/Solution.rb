# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)

  if nums.nil? or nums.size < 2
    return false
  end

  index_indicator = Hash.new

  nums.each_with_index { |key, index|

    if index_indicator.include? key

      if index - index_indicator[key] <= k
        return true
      else
        index_indicator[key] = index
      end

    else

      index_indicator[key] = index

    end
  }

  false
end