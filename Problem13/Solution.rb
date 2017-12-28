# @param {String} s
# @return {Integer}
def roman_to_int(s)

  #Contruct a conversion map.
  valueMap = {'I' => 1, 'V' => 5, 'X' => 10, 'L' => 50, 'C' => 100, 'D' => 500, 'M' => 1000}

  result = 0

  accumulator = 0

  currentMaxUnit = 0

  s.each_char do |ch|
    if result < valueMap[ch]
      result = valueMap[ch] - result

      currentMaxUnit = valueMap[ch]
    else
      if valueMap[ch] < currentMaxUnit

        accumulator += result

        result = 0

        currentMaxUnit = valueMap[ch]
      end

      result += valueMap[ch]
    end
  end

  accumulator += result
end

puts roman_to_int 'I'

puts roman_to_int 'V'

puts roman_to_int 'IVM'

puts roman_to_int "MCMXCVI"           # 1996
