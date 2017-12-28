require 'set'

# @param {Integer} n
# @return {Boolean}
def is_happy(n)

  presented = Set.new

  presented.add n

  while true

    next_num = 0

    unit_value = 0

    while n > 0

      unit_value = n % 10

      next_num += unit_value * unit_value

      n /= 10

    end

    if next_num == 1
      return true
    end

    if presented.include? next_num
      return false
    else
      presented.add next_num
    end

    n = next_num

  end
end

puts is_happy 19

puts is_happy 7