# @param {Integer[]} nums
# @return {Integer}
def majority_element(nums)

  statistic = Hash.new

  nums.each do |element|

    unless statistic.has_key? element
      statistic[element] = 0
    end

    statistic[element] += 1

  end

  target = 0; max_statistic = 0

  statistic.each_pair do |key, value|

    if value > max_statistic

      target = key

      max_statistic = value
    end

  end

  target

end

puts majority_element [1, 2, 2, 3]