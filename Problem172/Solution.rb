# @param {Integer} n
# @return {Integer}
def trailing_zeroes(n)

  ret = 0

  while n > 0

    ret += n/5

    n /= 5

  end

  ret

end

puts trailing_zeroes 25

puts trailing_zeroes 1808548329