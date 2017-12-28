# @param {Integer} a
# @param {Integer} b
# @return {Integer}
def get_sum(a, b)

  while b > 0

    current = a & b

    a = a ^ b

    b = current << 1
  end

  a
end

puts get_sum 1, 2

puts get_sum 4, 5