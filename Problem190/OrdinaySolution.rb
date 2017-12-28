# @param {Integer} n, a positive integer
# @return {Integer}
def reverse_bits(n)

  binary_present = n.to_s(2)

  binary_present.reverse!

  base_value = '0'.ord

  result = 0

  binary_present.each_char do |ch|
    result = result * 2 + ch.ord - base_value
  end

  result = result * 2**(32 - binary_present.size)

  result
end

puts reverse_bits 43261596                # Expected: 964176192