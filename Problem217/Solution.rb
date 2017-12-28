require 'set'

# @param {Integer[]} nums
# @return {Boolean}
def contains_duplicate(nums)

  if nums.nil? or nums.size < 2
    return false
  end

  presented = Set.new

  nums.each {|element|
    if presented.include? element
      return true
    else
      presented.add element
    end
  }

  false
end