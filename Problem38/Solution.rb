# @param {Integer} n
# @return {String}
def count_and_say(n)

  if n < 1
    return ''
  end

  if n == 1
    return 1.to_s
  end

  str = count_and_say (n - 1)

  currentValue = str[0]; count = 0

  newStr = ''

  str.each_char do |element|

    if currentValue == element
      count += 1
    else
      newStr += count.to_s + currentValue.to_s

      count = 1

      currentValue = element
    end

  end

  newStr += count.to_s + currentValue.to_s

end

puts count_and_say 1

puts count_and_say 2

puts count_and_say 3

puts count_and_say 4

puts count_and_say 5

puts count_and_say 6