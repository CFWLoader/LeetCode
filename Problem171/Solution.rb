# @param {String} s
# @return {Integer}
def title_to_number(s)

  if s.nil? or s.size < 1
    return 0
  end

  column_value = 0

  base_value = 'A'.ord

  s.each_char do |ch|

    column_value = column_value * 26 + ch.ord - base_value + 1

  end

  column_value

end

puts title_to_number 'A'

puts title_to_number 'B'

puts title_to_number 'Z'

puts title_to_number 'AA'