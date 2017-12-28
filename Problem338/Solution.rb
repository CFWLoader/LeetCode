# @param {Integer} num
# @return {Integer[]}
def count_bits(num)

  if num < 0
    return nil
  end

  if num == 0
    return [0]
  end

  result = Array.new num + 1

  result[0] = 0
  result[1] = 1

  bit_of_two = 1

  current_max_value = 2

  2.upto(num) {|val|

    if val >= current_max_value * 2

      bit_of_two += 1

      current_max_value *= 2

    end

    result[val] = result[val - current_max_value] + 1

  }

  result

end

target = count_bits 16

print target

puts