# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)

  one = two = three = 0

  # Using bits statistic.
  nums.each { |num|
    # Counting the bits occurred three times, twice, once.
    # The update sequence must be three times' count, twice's, once's because this can keep the date correctness.
    three = two & num         # The bits occurred twice. Now occurred one more time.
    two = two | one & num     # Occurred times is an even number.
    one = one | num           # Occurred once.

    # Make the records are distinct(Delete the records of occurred three times in once's and twice).
    one = one & ~three
    two = two & ~three
  }

  one

end


puts single_number [8, 2, 11, 39, 5, 11, 39, 39, 2, 8, 11, 8, 2]

puts single_number [1, 1, 1, 2, 3, 4, 4, 4, 2, 2]