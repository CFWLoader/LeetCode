# @param {Integer} n
# @return {String}
def count_and_say(n)

  if n < 10
    return n.to_s
  end

  stack = Array.new

  while n > 0

    stack << (n % 10)

    n /= 10

  end

  str = ''

  # print stack

  currentValue = stack[stack.size - 1]; count = 0

  stack.reverse_each do |element|

    if currentValue == element
      count += 1
    else
      str += count.to_s + currentValue.to_s

      count = 1

      currentValue = element
    end
  end

  str += count.to_s + currentValue.to_s

  str

end


puts count_and_say 110