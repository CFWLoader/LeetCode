# @param {Integer[]} digits
# @return {Integer[]}
def plus_one(digits)

  if digits.nil? or digits.size < 1
    return []
  end

  current = 1

  newValue = 0

  index = digits.size - 1

  while index > -1

    newValue = digits[index] + current

    digits[index] = newValue % 10

    current = newValue / 10

    index -= 1
  end

  if current != 0

    result = [current]

    result += digits
  else
    result = digits
  end

  result
end

print plus_one [1, 2, 3]

puts

print plus_one [9, 9]