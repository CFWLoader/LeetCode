# @param {Integer} num
# @return {String}
def int_to_roman(num)

  # Construct a conversion map.
  # valueMap = {1 => 'I', 5 => 'V', 10 => 'X', 50 => 'L', 100 => 'C', 500 => 'D', 1000 => 'M'}
  valueMap = Array.new 4

  valueMap[0] = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
  valueMap[1] = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
  valueMap[2] = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
  valueMap[3] = ['', 'M', 'MM', 'MMM']

  bits = Array.new 4

  bits[0] = num % 10
  num /= 10
  bits[1] = num %10
  num /= 10
  bits[2] = num % 10
  num /= 10
  bits[3] = num % 10

  index = 0

  str = ''

  while index < 4
    str = valueMap[index][bits[index]] + str

    index += 1
  end

  str
end


puts int_to_roman 1

puts int_to_roman 10

puts int_to_roman 3999